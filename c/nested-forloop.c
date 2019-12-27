#include <stdio.h>
#include <unistd.h>
int main() {

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) {
            printf("Nested loop is at: %d\n", j);
        }
    printf("First(main) loop is at: %d\n", i);
    }
}
