#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char *a = argv[1];
    char *aPtr;
    double aNum = strtod(a, &aPtr);

    char *c = argv[3];
    char *cPtr;
    double cNum = strtod(c, &cPtr);

    char usage[47] = "Run as:\ncalculator <number> <+-/x> <number>\n";
    // add help for which operators do what actions

    double result;

    // check for no argv[1,3]

    if (strcmp(argv[2], "+") == 0) {
        result = aNum + cNum;
    } else if (strcmp(argv[2], "-") == 0) {
        result = aNum - cNum;
    } else if (strcmp(argv[2], "/") == 0) {
        result = aNum / cNum;
    } else if (strcmp(argv[2], "x") == 0) {
        result = aNum * cNum;
    } else {
        printf("Unknown (middle) math operator. %s", usage);
        exit(0);
    }

    printf("%.2f\n", result);

    exit(0);
}
