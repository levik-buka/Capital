//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "mainform.h"
#include "aboutform.h"
#include "createaccountform.h"
#include "loginaccountform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CCALENDR"
#pragma resource "*.dfm"
TMainBox *MainBox;
//---------------------------------------------------------------------------
__fastcall TMainBox::TMainBox(TComponent* Owner)
        : TForm(Owner)
{
    Account = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainBox::ExitClick(TObject *Sender)
{
    Close ();
}
//---------------------------------------------------------------------------

void __fastcall TMainBox::AboutClick(TObject *Sender)
{
    AboutBox->ShowModal ();
}
//---------------------------------------------------------------------------

void __fastcall TMainBox::NewClick(TObject *Sender)
{
    if (!ConfirmAccountClose ()) return;

    if (CreateAccountBox->ShowModal () == mrOk)
    {
        Account = new CAccount (CreateAccountBox->AccountNameEdit->Text,
                                CreateAccountBox->PasswordEdit->Text);
        if (Account->Create ())
        {
            ShowMessage ("New account created.");
            EnableButtons ();
            RefreshSource ();
            Caption = Caption + " - " + Account->GetName();
        }
        else
        {
            ShowMessage (Account->GetError ());
            delete Account;
            Account = NULL;
        }
    }
}

bool TMainBox::ConfirmAccountClose (void)
{
    if (Account != NULL && Account->IsModified ())
    {
        String BeforeClose = "Would you like to save '"
                            + Account->GetName ()
                            + "' account before closing it?";
        int Check = Application->MessageBox (BeforeClose.c_str (),
                                            "Confirm!", MB_YESNOCANCEL);
        switch (Check)
        {
            case IDYES: Account->Save ();   // Save + Close
            case IDNO:  Account->Close ();  // Just Close
                        break;
            default: return false;          // Cancel
        }
    }

    Caption = Application->Title;
    DisableButtons ();
    delete (Account);
    Account = NULL;
    return true;
}

void TMainBox::EnableButtons (void)
{
    LogOut->Enabled = true;
    LogoutButton->Enabled = true;
    Save->Enabled = true;
    SaveButton->Enabled = true;
    Print->Enabled = true;
    PrintButton->Enabled = true;
    PrintPreview->Enabled = true;
    CopyMonth->Enabled = true;
    ExpensesMode->Enabled = true;
    RevenueMode->Enabled = true;
    Diffgraph->Enabled = true;
    ExpensesButton->Enabled = true;
    RevenueButton->Enabled = true;
    ViewBox->Enabled = true;
    ViewCompositor->Enabled = true;
    ChangePassword->Enabled = true;
    GraphButton->Enabled = true;
    ViewCompositorButton->Enabled = true;
}

void TMainBox::DisableButtons (void)
{
    LogOut->Enabled = false;
    LogoutButton->Enabled = false;
    Save->Enabled = false;
    SaveButton->Enabled = false;
    Print->Enabled = false;
    PrintButton->Enabled = false;
    PrintPreview->Enabled = false;
    CopyMonth->Enabled = false;
    ExpensesMode->Enabled = false;
    RevenueMode->Enabled = false;
    Diffgraph->Enabled = false;
    ExpensesButton->Enabled = false;
    RevenueButton->Enabled = false;
    ViewBox->Enabled = false;
    ViewCompositor->Enabled = false;
    ChangePassword->Enabled = false;
    GraphButton->Enabled = false;
    ViewCompositorButton->Enabled = false;

    CAESourceView->Items->Clear ();
    CARSourceView->Items->Clear ();
}

void TMainBox::RefreshSource (void)
{
    if (Account != NULL)
    {
        if (TabSheet2->Visible) // Expenses Mode
        {
            CAESourceView->LoadFromStream (Account->Log (EXPENSES_MODE));
        }
        else if (TabSheet3->Visible) // Revenue Mode
        {
            CARSourceView->LoadFromStream (Account->Log (REVENUE_MODE));
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainBox::FormCreate(TObject *Sender)
{
    DisableButtons ();
    StatusBar->Panels->Items [0]->Text += " "
        + MonthCalendar->Date.FormatString ("dd.mm.yyyy");
}
//---------------------------------------------------------------------------


void __fastcall TMainBox::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (!ConfirmAccountClose ()) Action = caNone;
}
//---------------------------------------------------------------------------


void __fastcall TMainBox::TabSheet3Show(TObject *Sender)
{
    RefreshSource ();
}
//---------------------------------------------------------------------------

void __fastcall TMainBox::TabSheet2Show(TObject *Sender)
{
    RefreshSource ();
}
//---------------------------------------------------------------------------

void __fastcall TMainBox::LogInClick(TObject *Sender)
{
    if (!ConfirmAccountClose ()) return;

    if (LoginAccountBox->ShowModal () == mrOk)
    {
        Account = new CAccount (LoginAccountBox->AccountNameEdit->Text,
                                LoginAccountBox->PasswordEdit->Text);
        if (Account->Open ())
        {
            EnableButtons ();
            RefreshSource ();
        }
        else
        {
            ShowMessage (Account->GetError ());
            delete Account;
            Account = NULL;
        }
    }
}
//---------------------------------------------------------------------------

