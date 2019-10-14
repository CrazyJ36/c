/*
    I wanted A tiny educational game that shows A word
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
    case'c':strcpy(word,"cat");break;
    case'd':strcpy(word,"dog");break;
    case'e':strcpy(word,"electricity");break;
    case'f':strcpy(word,"fire");break;
    case'g':strcpy(word,"game");break;
    case'h':strcpy(word,"hockey");break;
    case'i':strcpy(word,"ice");break;
    case'j':strcpy(word,"juice");break;
    case'k':strcpy(word,"ketchup");break;
    case'l':strcpy(word,"lion");break;
    case'm':strcpy(word,"mouse");break;
    case'n':strcpy(word,"nice");break;
    case'o':strcpy(word,"octopus");break;
    case'p':strcpy(word,"pipe");break;
    case'q':strcpy(word,"question");break;
    case'r':strcpy(word,"rooster");break;
    case's':strcpy(word,"strange");break;
    case't':strcpy(word,"titan");break;
    case'u':strcpy(word,"universe");break;
    case'v':strcpy(word,"velocity");break;
    case'w':strcpy(word,"word");break;
    case'x':strcpy(word,"xenon");break;
    case'y':strcpy(word,"yellow");break;
    case'z':strcpy(word,"zephyrhills");break;
    default:strcpy(word,"no entry for that.");break;
    }
    printf("%s\n", word);
    return 0;
}
