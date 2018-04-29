#include <stdio.h>

static int nln();

int main()
{
    int n = 1;
    printf("%d",n);
    printf("%s", " + 4 = ");
    int x = n + 4;
    printf("%d",x);
    nln();
}

int nln()
{
    printf("%s", "\n");
}
