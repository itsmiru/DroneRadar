//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "uCANDLL.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	char Serial[16];
	int nRet, nNum;
	nRet = uCAN_FindDevice(&nNum);

	cbDevice->Clear();
	for(int i=0;i<nNum;i++)
	{
		uCAN_GetSerial(i,Serial,15);
		cbDevice->Items->Add(String("uCAN HID Mode : ") + Serial);
	}
	cbDevice->ItemIndex = 0;
}
//---------------------------------------------------------------------------
