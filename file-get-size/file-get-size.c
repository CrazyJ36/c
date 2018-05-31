#include <stdio.h>
#include <sys/stat.h>

int main()
{
    struct stat mstat;
    stat("file.txt", &mstat);
    int size = mstat.st_size;
    printf("file is: %d bytes.\n", size);
}
