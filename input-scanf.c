#include <stdio.h>

int main(void)
{
// characters entered should be max of 5 characters or 'stack smashing detected' error
    char text[5];
// print instructions to user
    printf("Enter max of 5 characters: ");
// scanf (scan console) for input with(%s= data type-string), (assign input to var-text)
    scanf("%s", text);
// printf (%s means type of printed data will be string), (string content)
    printf("%s", "you entered: ");
// printf of type string using variable text.
    printf("%s", text);
// print formatted type string with newline \n as string data
    printf("%s", "\n");
// return to console as program executed sucsessfully
    return(0);
}

