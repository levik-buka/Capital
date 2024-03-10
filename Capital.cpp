//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEFORM("mainform.cpp", MainBox);
USEFORM("aboutform.cpp", AboutBox);
USEFORM("createaccountform.cpp", CreateAccountBox);
USEFORM("loginaccountform.cpp", LoginAccountBox);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
         Application->Initialize();
         Application->Title = "Capital 3 for Windows";
                 Application->CreateForm(__classid(TMainBox), &MainBox);
         Application->CreateForm(__classid(TAboutBox), &AboutBox);
         Application->CreateForm(__classid(TCreateAccountBox), &CreateAccountBox);
         Application->CreateForm(__classid(TLoginAccountBox), &LoginAccountBox);
         Application->Run();
        }
        catch (Exception &exception)
        {
            Application->ShowException(&exception);
            return -1;
        }

        return 0;
}
//---------------------------------------------------------------------------




