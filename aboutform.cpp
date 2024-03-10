//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "aboutform.h"

//---------------------------------------------------------------------
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//---------------------------------------------------------------------
__fastcall TAboutBox::TAboutBox(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TAboutBox::FormCreate(TObject *Sender)
{
    unsigned long InfoSize;
    char *InfoData;
    String AppName = Application->ExeName;

    if ((InfoSize = GetFileVersionInfoSize (AppName.c_str (), &InfoSize)) > 0)
    {
        InfoData = new char [InfoSize];
        GetFileVersionInfo(AppName.c_str (), 0, InfoSize, InfoData);

        ProductName->Caption = GetFileInfo (InfoData, "ProductName");
        Version->Caption = GetFileInfo (InfoData, "FileVersion") + " "
                            + GetFileInfo (InfoData, "ProductVersion");
        Copyright->Caption = GetFileInfo (InfoData, "LegalCopyright");
        Comments->Caption = GetFileInfo (InfoData, "Comments")
                             + "\nXerces-C++ library";
        delete InfoData;
    }
}

String TAboutBox::GetFileInfo (const LPVOID InfoData, const String &InfoParam)
{
    String FileInfo = "none";
    void *TempInfo;
    unsigned int DataSize;
    String Path = "\\StringFileInfo\\" + (String)HEX_LANG_CODE + "\\" + InfoParam;

    if (VerQueryValue (InfoData, Path.c_str (),
                       &TempInfo, &DataSize))
    {
        FileInfo = (char*)TempInfo;
    }

    delete TempInfo;
    return FileInfo;
}

//---------------------------------------------------------------------------

