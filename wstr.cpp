//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "wstr.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

wchar_t* WStr::Copy (const char* Text)
{
    WideString WString = Text;
    return WString.Copy ();
}

int WStr::Length (const wchar_t* Text)
{
    WideString WString = Text;
    return WString.Length ();
}


