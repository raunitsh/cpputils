#include "../includes/utils/RStringUtils.hpp"

void RStringUtils::CopyStr(const char *pSrc, char *pDest) {
  while (*pSrc != '\0') {
    *pDest = *pSrc;
    pSrc++;
    pDest++;
  }

  *pDest = '\0';
}

size_t RStringUtils::StrLen(const char *pStr) {
  const char *cursor = pStr;

  while (*cursor != '\0') {
    cursor++;
  }

  return cursor - pStr;
}

const char *RStringUtils::StrConcat(const char *pLhs, const char *pRhs) {
  size_t len1 = StrLen(pLhs);
  size_t len2 = StrLen(pRhs);

  char *start = new char [len1 + len2 + 1];

  CopyStr(pLhs, start);
  CopyStr(pRhs, start + len1);

  return start;
}