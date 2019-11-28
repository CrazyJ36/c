#include <stdio.h>

#define TEXT "Hello"

int main() {
    // Print length of TEXT
    int size_of_text = sizeof(TEXT) - 1;
    printf("Length of \'TEXT\' char-array, minus 1 for index 0 %d\n", size_of_text);
    printf("Printing characters in string: %s\n", TEXT);

    // Loop through char array TEXT
    for(int i = 0; i < sizeof(TEXT); i++) {

        // If the current char in loop is blank, skip by not printing.
        if(TEXT[i] == NULL) {
            continue;
        }

        // Print current char that is in i's loop index of TEXT.
        else {
            printf("char %d: %c\n", i, TEXT[i]);
        }
    }

    printf("Done..\n");
    return 0;
}
