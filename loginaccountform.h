//---------------------------------------------------------------------------
#ifndef loginaccountformH
#define loginaccountformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "createaccountform.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TLoginAccountBox : public TCreateAccountBox
{
__published:	// IDE-managed Components
    void __fastcall FormShow(TObject *Sender);
    void __fastcall OkButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TLoginAccountBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLoginAccountBox *LoginAccountBox;
//---------------------------------------------------------------------------
#endif
