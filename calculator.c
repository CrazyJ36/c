#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    double result;

    char *a = argv[1];
    char *aPtr;
    double aNum = strtod(a, &aPtr);

    const char *b = argv[2];

    char *c = argv[3];
    char *cPtr;
    double cNum = strtod(c, &cPtr);

    char usage[46] = "Run as:\n'calculator <number> <+-/x> <number>'.";

    if (argc < 4) {
        printf("To few arguments. %s\n", usage);
        exit(0);
    }
    else if (strcmp(argv[2], "+") == 0) {
        result = aNum + cNum;
    }
    else if (strcmp(argv[2], "-") == 0) {
        result = aNum - cNum;
    }
    else if (strcmp(argv[2], "/") == 0) {
        result = aNum / cNum;
    }
    else if (strcmp(argv[2], "x") == 0) {
        result = aNum * cNum;
    }
    else {
        printf("Middle math operator is unknown. %s\n",usage);
        exit(0);
    }

    printf("%.2f\n", result);

    exit(0);
}
