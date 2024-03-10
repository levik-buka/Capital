//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "createaccountform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCreateAccountBox *CreateAccountBox;
//---------------------------------------------------------------------------
__fastcall TCreateAccountBox::TCreateAccountBox(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TCreateAccountBox::OkButtonClick(TObject *Sender)
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
    else if (PasswordEdit->Text != VerifyPasswordEdit->Text)
    {
        ShowMessage ("Passwords don't match. Please, try again!");
        PasswordEdit->Text = "";
        VerifyPasswordEdit->Text = "";
        PasswordEdit->SetFocus ();
    }
    else
    {
        this->ModalResult = mrOk;
        this->DoHide ();
    }
}
//---------------------------------------------------------------------------

void __fastcall TCreateAccountBox::FormShow(TObject *Sender)
{
    AccountNameEdit->Text = "";
    PasswordEdit->Text = "";
    VerifyPasswordEdit->Text = "";
    AccountNameEdit->SetFocus ();
}
//---------------------------------------------------------------------------

