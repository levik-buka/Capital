//----------------------------------------------------------------------------
#ifndef aboutformH
#define aboutformH
//----------------------------------------------------------------------------
#include <vcl\System.hpp>
#include <vcl\Windows.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ExtCtrls.hpp>
//----------------------------------------------------------------------------

#define HEX_LANG_CODE "040904E4"

class TAboutBox : public TForm
{
__published:
	TPanel *Panel1;
	TImage *ProgramIcon;
	TLabel *ProductName;
	TLabel *Version;
	TLabel *Copyright;
	TLabel *Comments;
	TButton *OKButton;
    void __fastcall FormCreate(TObject *Sender);
private:
    String GetFileInfo (const LPVOID pBlock, const String &InfoParam);
public:
	virtual __fastcall TAboutBox(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TAboutBox *AboutBox;
//----------------------------------------------------------------------------
#endif    
