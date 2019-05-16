#include <stdio.h>
#include <time.h>

int main() {
  time_t rawtime; // time type
  struct tm * timeinfo; // structered time
  time(&rawtime); // make time with time_t type
  timeinfo = localtime(&rawtime); // struct has been set above, make it a localtime type
  printf("%s", asctime(timeinfo)); // print asctime
  return(0);
}
