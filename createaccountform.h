//---------------------------------------------------------------------------
#ifndef createaccountformH
#define createaccountformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TCreateAccountBox : public TForm
{
__published:	// IDE-managed Components
    TBevel *Bevel1;
    TLabel *Label1;
    TLabel *AccountNameLabel;
    TLabel *PasswordLabel;
    TLabel *VerifyPasswordLabel;
    TEdit *AccountNameEdit;
    TEdit *PasswordEdit;
    TEdit *VerifyPasswordEdit;
    TButton *OkButton;
    TButton *CancelButton;
    void __fastcall OkButtonClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TCreateAccountBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCreateAccountBox *CreateAccountBox;
//---------------------------------------------------------------------------
#endif
