#include <stdio.h>

int main() {
    char str1[12] = "hello world";
    int size = sizeof(str1);
    printf("Size of A char string containing 'hello world': %d\n", size);
    return 0;
}