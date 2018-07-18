#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // add help for which operators do what actions
    char usage[47] = "Usage:\ncalculator <num> <+-/x> <num>\n";

    // check for no argv[1,3]
    if ( !(argv[1]) || !(argv[2]) || !(argv[3]) ) {
    	printf("Invalid arguments.\n%s", usage);
    	exit(1);
    }

    char *a = argv[1];
    char *aPtr;
    double aNum = strtod(a, &aPtr);

    char *c = argv[3];
    char *cPtr;
    double cNum = strtod(c, &cPtr);

    double result;

    if (strcmp(argv[2], "+") == 0) { // 0 if true
        result = aNum + cNum;
    } else if (strcmp(argv[2], "-") == 0) {
        result = aNum - cNum;
    } else if (strcmp(argv[2], "/") == 0) {
        result = aNum / cNum;
    } else if (strcmp(argv[2], "x") == 0) {
        result = aNum * cNum;
    } else {
        printf("Invalid (middle) math operator. %s", usage);
        exit(0);
    }

    printf("%.2f\n", result);

    exit(0);
}
