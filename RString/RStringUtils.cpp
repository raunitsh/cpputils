#include "../includes/utils/RStringUtils.hpp"

// TODO: replace w RMemoryManager
#include <stdlib.h>

void
RStringUtils::CopyStr (const char*& pSrc, char*& pDest)
{
    while (*pSrc != '\0')
    {
        *pDest = *pSrc;
        pSrc++;
        pDest++;
    }

    *pDest = '\0';
}

size_t
RStringUtils::StrLen (const char* pStr)
{
    const char* cursor = pStr;

    while (*cursor != '\0')
    {
        cursor++;
    }

    return cursor - pStr;
}

const char*
RStringUtils::StrConcat (const char* pLhs, const char* pRhs)
{
    size_t len1 = StrLen (pLhs);
    size_t len2 = StrLen (pRhs);

    char* start = (char*)malloc (len1+len2+1);
    char* curr = start;

    CopyStr (pLhs, curr);
    curr--;
    CopyStr (pRhs, curr);

    return start;
}