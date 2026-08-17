#pragma once

#include <cstddef>

class RStringUtils {

    public:

static  void            CopyStr     (const char* pSrc, char* pDest);
static  size_t          StrLen      (const char* pStr);
static  const char*     StrConcat   (const char* pLhs, const char* pRhs);
};
