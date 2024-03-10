//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "account.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

CAccount::CAccount (const String &Name, const String &Password)
{
    this->Name = Name;
    this->Password = Password;

    CAEDoc = new TXMLDocument ("");
    CARDoc = new TXMLDocument ("");
}

CAccount::~CAccount ()
{
    delete CAEDoc;
    delete CARDoc;
}

bool CAccount::Create ()
{
    if (FileExists (Name + "." + (String)EXPENSES_FILETYPE)
        || FileExists (Name + "." + (String)REVENUE_FILETYPE))
    {
        Error = "Account with the '" + Name + "' name already exists.";
        return false;
    }

    CAEDoc->Active = true;

    return true;
}

bool CAccount::Open ()
{
    if (!FileExists (Name + "." + (String)EXPENSES_FILETYPE)
        || !FileExists (Name + "." + (String)REVENUE_FILETYPE))
    {
        Error = "Account with the '" + Name + "' name doesn't exist.";
        return false;
    }

    /* TODO: need try - catch  */
    CAEDoc->LoadFromFile (Name + "." + (String)EXPENSES_FILETYPE);
    CAEDoc->Active = true;

    return true;
}

bool CAccount::Save ()
{
    return true;
}

bool CAccount::Close ()
{
    CAEDoc->Active = false;
    CARDoc->Active = false;

    return true;
}

bool CAccount::IsModified (void)
{
    if (CAEDoc->Active && CARDoc->Active)
    {
        return CAEDoc->Modified & CARDoc->Modified;
    }
    return false;
}

String CAccount::GetName (void)
{
    return Name;
}

String CAccount::GetError (void)
{
    return Error;
}

TStream* CAccount::Log (int Account)
{
    TStringStream *XMLStr = new TStringStream ("");
    switch (Account)
    {
        case EXPENSES_MODE: if (CAEDoc->Active)
                            {
                                CAEDoc->SaveToStream(XMLStr);
                            }
                            break;
        case REVENUE_MODE : if (CARDoc->Active)
                            {
                                CARDoc->SaveToStream(XMLStr);
                            }
                            break;
    }
    XMLStr->Position = 0;

    return XMLStr;
}


