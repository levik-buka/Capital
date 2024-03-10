//---------------------------------------------------------------------------
#ifndef mainformH
#define mainformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>

#include "account.h"
#include "CCALENDR.h"
#include <Grids.hpp>
#include <ImgList.hpp>

//---------------------------------------------------------------------------
class TMainBox : public TForm
{
__published:	// IDE-managed Components
        TCoolBar *MainBar;
        TToolBar *FileToolBar;
        TToolButton *LoginButton;
        TToolButton *LogoutButton;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *SaveButton;
        TMainMenu *MainMenu;
        TMenuItem *File;
        TMenuItem *View;
        TMenuItem *LogIn;
        TMenuItem *LogOut;
        TMenuItem *N1;
        TMenuItem *Save;
        TMenuItem *N2;
        TMenuItem *Print;
        TMenuItem *N3;
        TMenuItem *Exit;
        TMenuItem *PrintPreview;
        TMenuItem *Help;
        TToolButton *PrintButton;
        TComboBox *ViewBox;
    TStatusBar *StatusBar;
        TToolBar *ModeToolBar;
        TToolButton *ExpensesButton;
        TToolButton *RevenueButton;
        TToolBar *ToolsToolBar;
        TToolButton *GraphButton;
        TMenuItem *N4;
    TMenuItem *Diffgraph;
        TMenuItem *Edit;
        TMenuItem *CopyMonth;
        TMenuItem *Contents;
        TMenuItem *N5;
        TMenuItem *About;
        TMenuItem *ExpensesMode;
        TMenuItem *RevenueMode;
        TMenuItem *Tools;
        TMenuItem *ViewCompositor;
        TMenuItem *New;
        TMenuItem *ChangePassword;
        TToolButton *ToolButton1;
        TToolButton *ViewCompositorButton;
    TSplitter *Splitter;
    TPageControl *PageControl;
    TTabSheet *TabSheet1;
    TTreeView *MonthView;
    TTabSheet *TabSheet2;
    TTabSheet *TabSheet3;
    TTreeView *CARSourceView;
    TTreeView *CAESourceView;
        TMonthCalendar *MonthCalendar;
        TImageList *ImageList;
        void __fastcall ExitClick(TObject *Sender);
    void __fastcall AboutClick(TObject *Sender);
    void __fastcall NewClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall TabSheet3Show(TObject *Sender);
    void __fastcall TabSheet2Show(TObject *Sender);
    void __fastcall LogInClick(TObject *Sender);
private:	// User declarations
    CAccount *Account;

    void EnableButtons (void);
    void DisableButtons (void);
    bool ConfirmAccountClose (void);
    void RefreshSource (void);
public:		// User declarations
        __fastcall TMainBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainBox *MainBox;
//---------------------------------------------------------------------------
#endif
