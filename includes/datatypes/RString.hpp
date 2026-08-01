#pragma once

/**
 *  RString - variable length string
 */
class RString {

    public:

                RString     ();
                RString     (const char* pSrc);

                ~RString    ();

const char*     GetPointer  ();
size_t          GetLength   ();

void            SetString   (const char* pSrc);
void            SetString   (RString* pSrc);

char            operator[]  (size_t pIdx);
RString&        operator=   (RString& pRHS);
RString         operator+   (RString& pRhs);

    private:

char*           vStr;
size_t          vLength;           
};