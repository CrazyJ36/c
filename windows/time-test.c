#include <stdio.h>
#include <time.h>

int main() {
    char buf[32]; // Blank char buffer to insert time string into
    printf("Time: %s\n", _strtime(buf)); // Put time from _strtime() into string, print it.
}