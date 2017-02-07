///
/// @file
/// @copyright All code copyright Movidius Ltd 2012, all rights reserved.
///            For License Warranty see: common/license.txt
///
/// @brief     main leon file 
///


// 1: Includes
// ----------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <rtems.h>
#include "sys/types.h"
#include <sys/socketvar.h>
#include "sys/socket.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "time.h"
#include <DrvTimer.h>
#include <DrvCpr.h>
#include <DrvLeon.h>

#include "http_shared.h"

// 2:  Source Specific #defines and types  (typedef, enum, struct)
// ----------------------------------------------------------------------------

// 3: Global Data (Only if absolutely necessary)
// ----------------------------------------------------------------------------

// 4: Static Local Data
// ----------------------------------------------------------------------------

// 5: Static Function Prototypes
// ----------------------------------------------------------------------------

// 6: Functions Implementation
// ----------------------------------------------------------------------------
int initClocksAndMemory(void)
{
    DrvCprInit();
    return 0;
}

void http_get(void)
{
    char buffer[1024];
    int s = socket(PF_INET, SOCK_STREAM, 0);
    if(s < 0) {
        printf("ERROR opening socket\n");
        exit(0); 
    }

    if( connect(s, (struct sockaddr *)server_addr, sizeof(struct sockaddr)) < 0 ) {
        printf("ERROR: Cannot connect to server %s!\n", inet_ntoa(server_addr->sin_addr));
        exit(0);
    }
    else 
        printf("Connection is successful to %s.\n", inet_ntoa(server_addr->sin_addr));

    strcpy(http_request, "GET /v1/dreamcloud/mf HTTP/1.0\r\n");
    strcpy(http_headers, "Content-Type: application/json\r\nContent-Length: %d\r\n\r\n");

    sprintf(buffer, http_request);
    int i = send(s, buffer, strlen(buffer), 0);
    if(i < 0) {
        printf("HTTP send failed\n");
        exit(0); 
    }
    else
        printf("HTTP send %d bytes\n", i);

    printf("HTTP response:\n");
    printf("\n************************************************************************\n");
    DrvTimerSleepMs(5000); //5s
    // While there's data, read and print it
    do
    {
        bzero(buffer, sizeof(buffer));
        i = recv(s, buffer, sizeof(buffer)-1, MSG_DONTWAIT); //last byte is null termination
        if (i > 0) 
            printf("%s", buffer);
    } while(i > 0);
    printf("\n************************************************************************\n");    
    close(s);
    exit(0);
}

int main(void)
{
	double timestamp_ms;

	initClocksAndMemory();
	
    printf("LeonRT: sleeping...\n");
    DrvTimerSleepMs(5000); //5s
    timestamp_ms = DrvTimerUptimeMs();
    printf("LeonRT: %f\n", timestamp_ms);

    http_get();
    DrvLeonRTSignalStop();

    return 0;
}