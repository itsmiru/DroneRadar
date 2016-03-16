#include <BaseTsd.h>

#define ON_CANRX			WM_USER+150
#define ON_CANERROR			WM_USER+160
#define ON_CANTX			WM_USER+170

#define NORMAL	0
#define BUSY	2

#define NO_ERR		0 	/* No Error		*/
#define STUFF_ERR	1	/* Stuff Error	*/
#define FORM_ERR	2	/* Form Error	*/
#define ACK_ERR		3 	/* AckError		*/
#define BIT1_ERR	4 	/* Bit1Error	*/
#define BIT0_ERR	5 	/* Bit0Error	*/
#define CRC_ERR		6 	/* CRCError		*/

#define RX_STD_DATA		0x04
#define RX_STD_REMOTE	0x05
#define RX_EXT_DATA		0x06
#define RX_EXT_REMOTE	0x07
#define TX_STD_DATA		0x14
#define TX_STD_REMOTE	0x15
#define TX_EXT_DATA		0x16
#define TX_EXT_REMOTE	0x17


struct CANFrame{
	UINT8 Format;
	UINT32 ID;
	UINT8 DLC;
	UINT8 Data[8];
	UINT64 TimeStamp; 
} typedef CAN_Frame;

struct CANError{
	UINT8 TEC; //Transmit Error Count
	UINT8 REC; //Receive Error Count
	UINT8 LEC; //Last Error Code
	UINT8 MODE;
	UINT16 Stuff_EC;
	UINT16 Form_EC;
	UINT16 Ack_EC;
	UINT16 Bit_EC;
	UINT16 CRC_EC;
} typedef CAN_Error;

struct CANMask{
	UINT32 ID;
	UINT32 MASK;
	UINT8 Format; 
} typedef CAN_Mask;


struct CANBTR{
	UINT8 BRP; 
	UINT8 SJW;
	UINT8 TSEG1;
	UINT8 TSEG2;
	UINT8 CLKDIV;
} typedef CAN_BTR;


//for initialization DLL
extern "C" long __stdcall uCAN_InitNotifyHandle(HANDLE hwnd);
extern "C" long __stdcall uCAN_DeInitNotifyHandle(void); 

//for initialization USB & find
extern "C" UINT8 __stdcall uCAN_Open(int index); 
extern "C" UINT8 __stdcall uCAN_FindDevice(int *MaxCount);
extern "C" UINT8 __stdcall uCAN_Close(void);
extern "C" UINT8 __stdcall uCAN_CAN_Enable(UINT8 enable);
extern "C" UINT8 __stdcall uCAN_GetBTR(UINT32 baud, CAN_BTR *btr);
extern "C" UINT8 __stdcall uCAN_GetBaudrate(UINT32 *baud, CAN_BTR btr);
extern "C" UINT8 __stdcall uCAN_GetSamplingPoint(float *SamplingPoint, CAN_BTR btr);
extern "C" UINT8 __stdcall uCAN_SendCANTxFrmae(CAN_Frame Tx);
extern "C" UINT8 __stdcall uCAN_SetSetting(CAN_BTR btr,CAN_Mask mask, UINT8 function);
extern "C" UINT8 __stdcall uCAN_GetSetting(CAN_BTR *btr,CAN_Mask *mask, UINT8 *function);
extern "C" UINT8 __stdcall uCAN_GetSerial(int index,char * strBuffer, UINT8 strBufferSize);
extern "C" UINT8 __stdcall uCAN_SetSerial(char * strBuffer, UINT8 strBufferSize);
extern "C" UINT8 __stdcall uCAN_GetErrorCount(void);