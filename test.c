#include <stdio.h>
#include <string.h>

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


void getWord(char word[WORD]){
    
    int counter = 0;
    char ch = getchar();
    while(ch!=' ' && ch!='\t' && ch!='\n'){
        word[counter] = ch;
        ch = getchar();
        counter++;
    }
}

int getCharGimatria(char ch){
    if('a'<=ch && ch<='z'){
        int value = (ch - 'a' +1);
        return value;
    }
    if('A'<=ch && ch<='Z'){
        int value = (ch - 'A' +1);
        return value;
    }
    return 0;
}


void getText(char txt[TXT]){
    
    int counter = 0;
    char ch = getchar();
    while(ch!='~'){
        txt[counter] = ch;
        ch = getchar();
        counter++;
    }
}

int getWordGimatria(char word[]){
    int sum = 0;
    int i = 0;
    while (word[i]){
        sum += getCharGimatria(word[i]);
        i++;
    }
    
    return sum;
}

void printGimatriaWords(int value, char txt[]){
    
    char to_print[TXT] = {};
    int txtLength = strlen(txt);
    
    for (int i = 0; i < txtLength; i++) {
        
        
        while(getCharGimatria(txt[i]) == 0){
            i++;
        }
        
        int j = i;
        int sum = 0;
        while(sum < value && j < txtLength){
            sum+= getCharGimatria(txt[j]);
            if(sum == value){
                if (strlen(to_print)>0){
                    printf("%s~", to_print);    
                }
                updateToPrintSTR(txt, i, j, to_print);
            }
            j++;
        }
    }
    
    if (strlen(to_print)>0){
        printf("%s", to_print);    
    }
}


void updateToPrintSTR(char txt[], int i, int j, char to_print[]){
    int index = 0;
    for (; i <= j; i++) {
        to_print[index] = txt[i];
        index++;
    }
    to_print[index] = 0;
}


void changeAtbash(char str[]){
    for (int i = 0; i < strlen(str); i++) {
        if('a'<=str[i] && str[i]<='z'){
            str[i] = ('z'- str[i] + 'a');
        }
        
        if('A'<=str[i] && str[i]<='Z'){
            str[i] = ('Z'- str[i] + 'A');
        }
    }
}


void printAtbashWords(char word[], char txt[]){
    
    char to_print[TXT] = {};
    int txtLength = strlen(txt);
    char atbashWord[strlen(word)];
    strcpy(atbashWord, word);
    changeAtbash(atbashWord);
    int value = getWordGimatria(atbashWord);
    
    for (int i = 0; i < txtLength; i++) {
        
        while(txt[i] == ' '){
            i++;
        }
        
        int j = i;
        int sum = 0;
        while(sum < value && j < txtLength){
            sum+= getCharGimatria(txt[j]);
            
            if(sum == value){
                if(sameLettersOrder(txt, i, j, atbashWord) || reverseLettersOrder(txt, i, j, atbashWord)){
                    
                    if (strlen(to_print)>0){
                        printf("%s~", to_print);
                    }
                    updateToPrintSTR(txt, i, j, to_print);
                }
            }
            j++;
        }
    }
    
    if (strlen(to_print)>0){
        printf("%s", to_print);    
    }
}


int sameLettersOrder(char txt[], int i, int j, char word[]){
    
    int counter = 0;
    for(;i <= j; i++){
        
        if(txt[i] != ' '){
            if(txt[i] != word[counter]){
                return 0;
            }
            counter++;
        }
    }
    return 1;
}


int reverseLettersOrder(char txt[], int i, int j, char word[]){
    int counter = 0;
    for(;j >= i; j--){

        if(txt[j] != ' '){
            if(txt[j] != word[counter]){
                return 0;
            }
            counter++;
        }
    }
    return 1;
}


void deleteChar(char str[], int index){
    while(str[index] != 0){
        str[index] = str[index+1];
        index++;
    }
}


void printAnagram(char word[], char txt[]){
    
    char to_print[TXT] = {};
    int txtLength = strlen(txt);
    int word_size = strlen(word);
    
    for (int i = 0; i < txtLength; i++) {
        
        while(txt[i] == ' '){
            i++;
        }
        
        int index = i;
        
        char copy_word[word_size];
        strcpy(copy_word, word);
        int loc = 0;
        
        while(strlen(copy_word) > 0 && index < txtLength){
            
            if(txt[index] == ' '){
                index++;
                continue;
            }
            loc = getLocation(copy_word, txt[index]);
            if (loc == -1){
                break;
            }
            else{
                deleteChar(copy_word, loc);
                index++;
            }
        }
        if(strlen(copy_word) == 0){
            if (strlen(to_print)>0){
                printf("%s~", to_print);    
            }
            updateToPrintSTR(txt , i, index-1, to_print);
        }
    }
    if (strlen(to_print)>0){
        printf("%s", to_print);    
    }
}

int getLocation(char word[], char ch){
    int index = -1;
    for (int i = 0; i < strlen(word) && word[i] != 0; i++) {
        if(word[i] == ch){
            index = i;
            return index;
        }
    }
    return index;
}


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