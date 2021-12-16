#include <stdio.h>
#include <string.h>
#include "funcs.h"

int main()
{
    char w[WORD] = {};
    char t[TXT] = {};
    
    getWord(w);
    getText(t);
    
    int wordValue = getWordGimatria(w);

    printf("Gematria Sequences: ");
    printGimatriaWords(wordValue, t);
    
    printf("\nAtbash Sequences: ");
    printAtbashWords(w, t);
    
    printf("\nAnagram Sequences: ");
    printAnagram(w, t);
    
    return 0;
}
