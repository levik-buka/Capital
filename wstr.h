//---------------------------------------------------------------------------
#ifndef wstrH
#define wstrH
//---------------------------------------------------------------------------
#include <vcl/wstring.h>

class WStr
{
public:
    static wchar_t* Copy (const char* Text);
    static int Length (const wchar_t* Text);
};

#endif
 