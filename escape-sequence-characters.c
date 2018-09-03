/* In basic form, ANSI C defines two character sets(a lists of characters):
   - Source character set - recognized characters usable in source files.
   - Execution character set - characters that are interpreted during execution.
   - Extended character set - includes more or all possible characters.

   Each character set includes a basic character set:
   - all letters of the alphabet, in upper and lower case form (52 total).
   - 0-9 numbers
   - 29 graphic characters (on keyboard)
   - the five white space characters: Space, horizontal tab, vertical tab, newline, form feed.
   - also: the null character(\0 - terminates a character string),
     and the escape secuence charaters:
     \a beep alert	  \' apostraphe
     \b backspace	  \" double quote
     \f form feed         \? question mark
     \n new line          \\ backslash
     \r carriage return   \o.. octal code (o = octal digit)
     \t horizontal tab    \xh.. hexadeciam code (h.. = string of hex digits)
     \v vertical tab
    - from C99:
      ??=  -  #
      ??(  -  [
      ??/  -  \
      ??)  -  ]
      ??'  -  ^
      ??<  -  {
      ??!  -  |
      ??>  -  }
      ??-  -  ~
*/
int main()
{
  printf("\v"); // simply prints vertical tab (4 new lines).

printf("Examples of escape characters and how to 'escape' them\n\n");

 printf("The percent sign(%%) usually is used to insert A variable into a printf charsequence.\n");
 printf("To use it as text, it must be escaped in such A way that C knows\n");
 printf("the first percent sign you type is not used as A placeholder.\n");
 printf("You should type %%%%(two percents) in order to use a percent symbol as text:\n");
 printf("output: %%\n");
 return(0);
}
