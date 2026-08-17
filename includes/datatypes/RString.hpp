#pragma once

#include <cstddef>

/**
 *  RString - variable length string
 */
class RString {

    public:

                RString     ();
                RString     (const char* pSrc);

                ~RString    ();

const char*     GetPointer  ()  const;
size_t          GetLength   ()  const;

void            SetString   (const char* pSrc);
void            SetString   (const RString* pSrc);

char            operator[]  (size_t pIdx);
RString&        operator=   (const RString& pRHS);
RString         operator+   (const RString& pRhs);

    private:

char*           vStr;
size_t          vLength;           
};
