/**
  LIN Slave Application

  Company:
    Microchip Technology Inc.

  File Name:
    lin_app.c

  Summary:
    LIN Slave Application

  Description:
    This source file provides the interface between the user and
    the LIN drivers.

 */

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

#include "lin_app.h"
#include <xc.h>

#define SW1_KEY 0B00100000  // 0x20 data[5]
#define SW2_KEY 0B00000010  // 0x02 data[2]
#define SW3_KEY 0B00000001  // 0x01 data[2]
#define SW4_KEY 0B11000000  // 0xC0 data[1]
#define SW5_KEY 0B00110000  // 0x30 data[1]

//#include "..\build\mcc_generated_files\pin_manager.h"
 #include "..\pin_manager.h"

void LIN_Slave_Initialize(void) {

    LIN_init(TABLE_SIZE, scheduleTable, processLIN);
}

void processLIN(void) {
    uint8_t tempRxData[8];
    uint8_t cmd;

    cmd = LIN_getPacket(tempRxData);
    switch (cmd) {

        case SW_STATE:
            if ( (tempRxData[5] & SW1_KEY) == SW1_KEY) {
                LED1_SetHigh();
            } else {
                LED1_SetLow();
            }

            if ( (tempRxData[2] & SW2_KEY) == SW2_KEY) {
                LED2_SetHigh();
            } else {
                LED2_SetLow();
            }

            if ( (tempRxData[2] & SW3_KEY) == SW3_KEY) {
                LED3_SetHigh();
            } else {
                LED3_SetLow();
            }

            if ( (tempRxData[1] & SW4_KEY) == SW4_KEY) {
                LED4_SetHigh();
            } else {
                LED4_SetLow();
            }

            if ( (tempRxData[1] & SW5_KEY) == SW5_KEY) {
                LED5_SetHigh();
            } else {
                LED5_SetLow();
            }

            break;

        default:
            break;
    }
}
