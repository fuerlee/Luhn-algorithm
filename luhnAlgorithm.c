  #include <stdlib.h> // atoi
  #include <string.h> // strlen
  #include <stdbool.h> // bool

  bool checkLuhn(const char *pPurported)
  {
    int nSum       = 0;
    int nDigits    = strlen(pPurported);
    int nParity    = (nDigits-1) % 2;
    char cDigit[2] = "\0";
    for (int i = nDigits; i > 0 ; i--)
    {
      cDigit[0]  = pPurported[i-1];
      int nDigit = atoi(cDigit);

      if (nParity == i % 2)
        nDigit = nDigit * 2;

      nSum += nDigit/10;
      nSum += nDigit%10;
    }
    return 0 == nSum % 10;
  }