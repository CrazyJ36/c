/* Functions are central to C.
   declaration must be declared before main():
     returnType functionName(parameters);

   - returnType is the type of value the function sends back to the calling statement that uses this function.
   - function name followed by ().
   - (type parameters) Optional parameter names with type.
   When the parameter types and names are included in a declaration, the declaration is called a 'function prototype'.
*/


#include <stdio.h>

static int nln(); /* static int functionName(); should be declared
to the file to show the function as constant, accessible to
avoid error. */

int main() {
 nln(); //using the function(below) here.
 printf("New line");
 nln();
 printf("Another new line");
 nln();
 return(0);
}

// creating function here. It simply makes a blank line..
int nln() {
 printf("\n\n");
 return(0);
}
