#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr; // handles all memory allocation of this program.
    int n;
    printf("Enter A number of array items that you'll enter later.\nThis will all be placed in the variable ptr: ");
    scanf("%d", &n);
    ptr = (int*) calloc(n, sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated. Exiting.\n");
        free(ptr);
        return 0;
    }
    else {
        printf("Memory allocated sucessfully for your array. Enter integer array items on their own lines in this loop: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &ptr[i]);
        }
        printf("The elements of the int array are: ");
        for (int j = 0; j < n; j++) {
            printf("%d ", ptr[j]);
        }
        printf("\n");
    }
    printf("Freeing variable 'ptr' which contains your array. Always free() all pointers in the system before exiting your program.\n \
        You can also free some initialized variables which use functions eg. HWND hWnd = CreateWindowEx() to make the program close faster.\n");
    free(ptr);
    
    return 0;
}