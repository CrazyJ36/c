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
  return(0);
}
