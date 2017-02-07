#ifndef _HTTP_SHARED_H_
#define _HTTP_SHARED_H_

// Includes
// ----------------------------------------------------------------------------
#include "mv_types.h"
#include <netinet/in.h>
/*#include <rtems.h>
#include "rtems/rtems_bsdnet.h" //rtems_bsdnet_initialize_network()
#include "sys/types.h"
#include <sys/socketvar.h>
#include "sys/socket.h"
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
//#include "OsDrvTimer.h"
#include "rtems/dhcp.h"
//#include "time.h"
//#include <DrvTimer.h>
//#include <DrvCpr.h>
//#include "http_shared.h"
//#include "rtems_config.h"*/

extern char http_host_name[128];
extern char http_request[128];
extern char http_headers[128];
extern struct sockaddr_in *server_addr;
// Exported Functions (non-inline)
// ----------------------------------------------------------------------------
void EthPHYHWReset(void);
void InitGpioEth(u8 invertGtxClk);
void initGrethAndNet(void);
void getServerAddr(void);

#endif