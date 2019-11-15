/* print-no-header.c
 *
 * Recreated by CrazyJ36
 *
 * Prints to stdout using the same function definition
 * from stdio, but does not include it.
 * C still knows to print to stdout due
 * to linked crt (screen) libs.
*/

// Declare the printf function ourselfs in basic form.
int printf(const char *format, ...);

int main()
{
  printf("Hello STDOUT\n");
  return(0);
}
