/*
    I wanted A yiny educational game that shows A word
    that starts with any letter you type.
    Instead of if/else:
    ________
    if (mChar == 'a') {
        printf("apple\n");
    } else if (mChar == 'b') {
        printf("banana\n");
    } else {
        printf("I have nothing for %c\n", mChar);
    }
    ________
    do:
    ________
    char name[10]
    switch (name) {
    case 'a':
      strcpy(name, "aword"); copy "aeord" string to name[] pointer
      break;
    ________
*/

#include <stdio.h>
#include <string.h>

int main()
{
    printf("Enter A character a-z\n");
    char mChar = getchar();
    char word[20];
    switch(mChar){
    case'a':strcpy(word,"apple");break;
    case'b':strcpy(word,"banana");break;
    default:strcpy(word,"no entry for that.\n");break;
    }
    printf("%s\n", word);
    return 0;
}
