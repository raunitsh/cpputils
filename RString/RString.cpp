#include "../includes/datatypes/RString.hpp"
#include "../includes/utils/RStringUtils.hpp"

// TODO: Replace with RMemoryManager
#include<stdlib.h>

RString::RString ()
{
    vStr = nullptr;
    vLength = 0;
}

RString::RString (const char* pSrc)
{
    size_t len = RStringUtils::StrLen (pSrc);
    vStr = (char*) malloc (len+1);

    RStringUtils::CopyStr (pSrc, vStr);
    vLength = len;
}

RString::~RString ()
{
    free (vStr);
    vStr = nullptr;
}

const char* RString::GetPointer ()
{
    return (const char*)vStr;
}

void
RString::SetString (const char* pSrc)
{
    if (vStr)
        free (vStr);

    size_t len = RStringUtils::StrLen (pSrc);

    vStr = (char*) malloc (len + 1);
    RStringUtils::CopyStr (pSrc, vStr);
    vLength = len;
}

void
RString::SetString (RString* pSrc)
{
    if (vStr)
        free (vStr);

    vStr = (char*) malloc (pSrc->GetLength() + 1);
    const char* src = pSrc->GetPointer();
    RStringUtils::CopyStr (src, vStr);
}

size_t
RString::GetLength ()
{
    return vLength;
}

char
RString::operator[] (size_t pIdx)
{
    return vStr[pIdx];
}

RString&
RString::operator= (RString& pRHS)
{
    SetString (&pRHS);
    return *this;
}

RString
RString::operator+ (RString& pRhs)
{
    return RString (RStringUtils::StrConcat (vStr, pRhs.GetPointer()));
}