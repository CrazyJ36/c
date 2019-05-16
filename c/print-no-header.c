// print-no-header.c

/* Prints to stdout using function from stdio, but does not include it.
   Seems it still knows to print to stdout due to linked crt (screen) libs
*/

// Declare printf function ourselfs in basic form.
int printf(const char *format, ...);

int main()
{
  printf("Hello STDOUT\n");
  return(0);
}
