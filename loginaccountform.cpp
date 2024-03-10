//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "loginaccountform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "createaccountform"
#pragma resource "*.dfm"
TLoginAccountBox *LoginAccountBox;
//---------------------------------------------------------------------------
__fastcall TLoginAccountBox::TLoginAccountBox(TComponent* Owner)
    : TCreateAccountBox(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLoginAccountBox::FormShow(TObject *Sender)
{
    AccountNameEdit->Text = "";
    PasswordEdit->Text = "";
    AccountNameEdit->SetFocus ();
}
//---------------------------------------------------------------------------
void __fastcall TLoginAccountBox::OkButtonClick(TObject *Sender)
{
    if (AccountNameEdit->Text == "")
    {
        ShowMessage ("Insert account name.");
        AccountNameEdit->SetFocus ();
    }
    else if (PasswordEdit->Text == "")
    {
        ShowMessage ("Insert password.");
        PasswordEdit->SetFocus ();
    }
    else
    {
        this->ModalResult = mrOk;
        this->DoHide ();
    }
}
//---------------------------------------------------------------------------
