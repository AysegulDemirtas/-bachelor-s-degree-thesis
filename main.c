#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define UINT unsigned int
#define BYTE unsigned char
#define BYTESIZE CHAR_BIT
#define BLOCKSIZE BYTESIZE
#define KEYSIZE 10
#define SUBKEYSIZE 8
#define SPLITKEYSIZE 5
BYTE ctext = 0;
BYTE E[] = {0,1,0,0,2,3,3,2};
BYTE P4[] = {1,0,3,2};
BYTE S0[]={1,0,2,3,3,1,0,2,2,0,3,1,1,3,2,0};
BYTE S1[]={0,3,1,2,3,2,0,1,1,0,3,2,2,1,3,0};

UINT cbin2UINT(char *s, unsigned int nSize);
int main(){

    printf("String 11011001 is %u\n", cbin2UINT("11011001",BYTESIZE));
    printf("String 1011011001 is %u\n", cbin2UINT("1011011001",KEYSIZE));
   
    return 0;}


/* bu fonksiyonda  (nSize - nLen - 1) kadar sola 1 i shift ediyor ve sonuna uresult ı koyuyor yani binary sayıyı unsigned integer a çeviriyor.  */
 
UINT cbin2UINT(char *s, unsigned int nSize){
        int nLen = strlen(s);
        UINT uResult = 0;
    while (--nLen >= 0){
            if(s[nLen] == '1')
                uResult = 1 << (nSize - nLen - 1) | uResult;
   // printf(" %d\n",uResult);
    }
    
        return uResult;
    
    }