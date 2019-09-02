/*  Using parameters in funtions requires:
    - format daclaration before main(). As: return_type function_name(type parameter, type parameter);
    Any function can be called in main using any parameter value.

    When arguments are passed to function patameters, the parameters act as local variables.
    Upon exititng A function, parameters and any local variables(with one code block) in the function are deleted.

*/

void addNum(int num, int num2);
int returnThing();

#include <stdio.h>

int main() {
  addNum(1,2);
  int xin = returnThing(); // The way of using return value of returnThing()
  printf("%d\n",xin);
  return(0);
}

// function with parameters
void addNum(int num, int num2) {
  int result;
  result = num + num2; // A value like this can be returned to main() using: return(result);
 		       // for this the function_type should be int instead of void. Example below.
  printf("%d + %d = %d\n", num, num2, result);
}

// function that returns data to main()
int returnThing() { // return_type function_name()
  int x = 3; // define thing to return
  return(x); // return x to calling statement when called upon
}
