/*********************************************************************
 *
 *                Microchip USB C18 Firmware 
 *
 *********************************************************************

#ifndef IO_CFG_H
#define IO_CFG_H

/** I N C L U D E S *************************************************/
#include "usbcfg.h"

/** T R I S *********************************************************/
#define INPUT_PIN           1
#define OUTPUT_PIN          0

#if defined(PIC18F4550_PICDEM_FS_USB) || defined(PIC18F4550_PICDEM_FS_USB_K50)
/** U S B ***********************************************************/
#define tris_usb_bus_sense  TRISAbits.TRISA1    // Input

#if defined(USE_USB_BUS_SENSE_IO)
#define usb_bus_sense       PORTAbits.RA1
#else
#define usb_bus_sense       1
#endif

#define tris_self_power     TRISAbits.TRISA0    // Input

#if defined(USE_SELF_POWER_SENSE_IO)
#define self_power          PORTAbits.RA0
#else
#define self_power          1
#endif
/*
// External Transceiver Interface
#define tris_usb_vpo        TRISBbits.TRISB3    // Output
#define tris_usb_vmo        TRISBbits.TRISB2    // Output
#define tris_usb_rcv        TRISAbits.TRISA4    // Input
#define tris_usb_vp         TRISCbits.TRISC5    // Input
#define tris_usb_vm         TRISCbits.TRISC4    // Input
#define tris_usb_oe         TRISCbits.TRISC1    // Output

#define tris_usb_suspnd     TRISAbits.TRISA3    // Output
 */

/** L E D ***********************************************************/
#define mInitAllLEDs()      LATE &= 0xF8; TRISE &= 0xFC;
//#define mInitAllLEDs()      LATE &= 0xF8; TRISE &= 0xF8;

#define mLED_1              LATEbits.LATE0
#define mLED_2              LATEbits.LATE1
//#define mLED_3              LATEbits.LATE2

#define mLED_1_On()         mLED_1 = 1;
#define mLED_2_On()         mLED_2 = 1;
//#define mLED_3_On()         mLED_3 = 1;

#define mLED_1_Off()        mLED_1 = 0;
#define mLED_2_Off()        mLED_2 = 0;
//#define mLED_3_Off()        mLED_3 = 0;

#define mLED_1_Toggle()     mLED_1 = !mLED_1;
#define mLED_2_Toggle()     mLED_2 = !mLED_2;

/** S W I T C H *****************************************************/

//#define mInitSwitch2()       TRISCbits.TRISC6=1;ANSELC = 0x00;//apr25
//#define sw2                 PORTCbits.RC6//apr25


#if defined(PIC18F4550_PICDEM_FS_USB_K50)
    #define PIR2bits  PIR3bits
    #define PIE2bits  PIE3bits
#endif


#endif //IO_CFG_H
