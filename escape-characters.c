#include <stdio.h>

int main()
{
 printf("Examples of escape characters and how to 'escape' them\n\n");

 printf("The percent sign(%%) usually is used to insert A variable into a printf charsequence.\n");
 printf("To use it as text, it must be escaped in such A way that C knows\n");
 printf("the first percent sign you type is not used as A placeholder.\n");
 printf("You should type %%%%(two percents) in order to use a percent symbol as text:\n");
 printf("output: %%\n");

 return(0);
}
