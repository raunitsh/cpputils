#include "../includes/datatypes/RString.hpp"
#include "../includes/utils/RStringUtils.hpp"

RString::RString ()
{
    vStr = nullptr;
    vLength = 0;
}

RString::RString (const char* pSrc)
{
    size_t len = RStringUtils::StrLen (pSrc);
    vStr = new char[len+1];

    RStringUtils::CopyStr (pSrc, vStr);
    vLength = len;
}

RString::~RString ()
{
    delete vStr;
    vStr = nullptr;
}

const char* RString::GetPointer () const
{
    return (const char*)vStr;
}

void
RString::SetString (const char* pSrc)
{
    if (vStr)
        delete vStr;

    size_t len = RStringUtils::StrLen (pSrc);

    vStr = new char [len + 1];
    RStringUtils::CopyStr (pSrc, vStr);
    vLength = len;
}

void
RString::SetString (const RString* pSrc)
{
    if (vStr)
        delete vStr;

    vStr = new char [pSrc->GetLength() + 1];
    const char* src = pSrc->GetPointer();
    RStringUtils::CopyStr (src, vStr);
}

size_t
RString::GetLength () const
{
    return vLength;
}

char
RString::operator[] (size_t pIdx)
{
    return vStr[pIdx];
}

RString&
RString::operator= (const RString& pRHS)
{
    SetString (&pRHS);
    return *this;
}

RString
RString::operator+ (const RString& pRhs)
{
    return RString (RStringUtils::StrConcat (vStr, pRhs.GetPointer()));
}