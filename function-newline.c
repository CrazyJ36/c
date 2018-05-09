#include <stdio.h>

static int nln(); /* static int functionName(); should be defined 
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
