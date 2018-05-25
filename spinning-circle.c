#include <stdio.h>
#include <unistd.h>
int main() {

    char arr[3] = {'|','\\','/'};

    for (int i = 0; i < 1; i++) {

        for (int j = 0; j < 4; j++) {
            printf("Nested loop is at: %d\n", j);

            int x = 0;
            char y = arr[x];
            printf("%c", y);
            x++;
        }

    printf("First(main) loop is at: %d\n", i);
    }
}
