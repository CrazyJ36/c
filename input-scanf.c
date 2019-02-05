/* The scanf() function from stdio.h allows
   receiving input from stdin(terminal by default)
   in A formatted way, to get only
   characters that are required.
*/
#include <stdio.h>

int main(void)
{
// characters entered should be max of 5 characters or 'stack smashing detected' error
    char text[5];
// print instructions to user
    printf("Enter max of 5 characters: ");
// scanf (scan console) for input with(%s= data type-string), (assign input to var-text)
    scanf("%s", text); // it seems that compilers would rather have an '&' before re-using a
                       // variable. eg: &text sometimes warnings are shown otherwise.
// printf (%s means type of printed data will be string), (string content)
    printf("%s", "you entered: ");
// printf of type string using variable text.
    printf("%s", text);
// print formatted type string with newline \n as string data
    printf("%s", "\n");
// return to console as program executed sucsessfully
    return(0);
}

