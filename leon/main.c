///
/// @file
/// @copyright All code copyright Movidius Ltd 2012, all rights reserved.
///            For License Warranty see: common/license.txt
///
/// @brief     Main leon file
///

// 1: Includes
// ----------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <rtems.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <DrvLeon.h>
#include <OsDrvCpr.h>
#include "rtems/rtems_bsdnet.h" //rtems_bsdnet_initialize_network()
#include <assert.h>
#include "sys/types.h"
#include <sys/socketvar.h>
#include "sys/socket.h"
#include <netinet/in.h>
#include "netdb.h" //gethostbyname
#include <sys/ioctl.h>
#include "net/if.h"
#include "net/if_var.h"
#include "arpa/inet.h"
#include "sys/proc.h"
#include <bsp/greth_gbit.h>
#include <bsp.h>
#include "DrvGpio.h"
#include "DrvI2cMaster.h"
#include "DrvI2c.h"
#include "OsDrvCpr.h"
#include "OsDrvTimer.h"
#include "rtems/dhcp.h"
#include "time.h"
#include <DrvTimer.h>
#include <DrvCpr.h>

#include "http_shared.h"
#include "rtems_config.h"

// This have a big impact in Gigabit mode (at least for loopback test), set to  1 or 0
#define INVERT_GTX_CLK_CFG                              1
extern u32 *lrt_start;
// 5: Static Function Prototypes
// ----------------------------------------------------------------------------

// 6: Functions Implementation
// ----------------------------------------------------------------------------

void POSIX_Init (void *args)
{
    UNUSED(args);

    s32 sc;

    sc = initClocksAndMemory();
    if(sc)
        exit(sc);

    EthPHYHWReset();
    InitGpioEth(INVERT_GTX_CLK_CFG);
    initGrethAndNet();
    getServerAddr();

    printf("LeonOS Started.\n");
    printf("LeonRT Start Addr: 0x%lX\n",(u32)&lrt_start);

    // Start the LeonRT application
    DrvLeonRTStartup((u32)&lrt_start);
    DrvLeonRTWaitExecution();

    printf("LeonRT Stop.\n");

    exit(0);
}

// User extension to be able to catch abnormal terminations
static void Fatal_extension(
  Internal_errors_Source  the_source,
  bool                    is_internal,
  uint32_t                the_error
)
{
    switch(the_source)
    {
    case RTEMS_FATAL_SOURCE_EXIT:
		if(the_error)
		    printk("Exited with error code %d\n", the_error);
        break; // normal exit
    case RTEMS_FATAL_SOURCE_ASSERT:
        printk("%s : %d in %s \n",
               ((rtems_assert_context *)the_error)->file,
               ((rtems_assert_context *)the_error)->line,
               ((rtems_assert_context *)the_error)->function);
        break;
    case RTEMS_FATAL_SOURCE_EXCEPTION:
        rtems_exception_frame_print((const rtems_exception_frame *) the_error);
        break;
    default:
        printk ("\nSource %d Internal %d Error %d  0x%X:\n",
                the_source, is_internal, the_error, the_error);
        break;
    }
}
