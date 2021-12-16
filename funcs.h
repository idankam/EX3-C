#ifndef HEADERS
#define HEADERS

#define TXT 1025
#define WORD 31

void getWord(char word[WORD]);
void getText(char txt[TXT]);
int getCharGimatria(char ch);
int getWordGimatria(char word[]);
void printGimatriaWords(int value, char txt[]);
void updateToPrintSTR(char txt[], int i, int j, char to_print[]);
void changeAtbash(char str[]);
int sameLettersOrder(char txt[], int i, int j, char word[]);
void printAtbashWords(char word[], char txt[]);
int reverseLettersOrder(char txt[], int i, int j, char word[]);
void deleteChar(char str[], int index);
void printAnagram(char word[], char txt[]);
void changeAtbash(char str[]);
int getLocation(char word[], char ch);

#endif