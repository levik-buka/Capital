//---------------------------------------------------------------------------
#ifndef accountH
#define accountH
//---------------------------------------------------------------------------

#include <oxmldom.hpp>
#include <XMLIntf.hpp>
#include <XMLDoc.hpp>

#include "wstr.h"

#define EXPENSES_FILETYPE "cae"
#define REVENUE_FILETYPE  "car"
#define EXPENSES_MODE 0
#define REVENUE_MODE  1


static const String CAERootName = "CapitalExpenses";

class CAccount
{
private:	// User declarations
    String Name;
    String Password;
    String Error;

    TXMLDocument *CAEDoc;
    TXMLDocument *CARDoc;

protected:

public:		// User declarations
    CAccount (const String &Name, const String &Password);
    ~CAccount ();

    bool Create (void);
    bool Open (void);
    bool Save (void);
    bool Close (void);

    bool IsModified (void);
    String GetName (void);
    String GetError (void);

    TStream* Log (int Account);

};
#endif
