#include <alsa/version.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
/*  From file: '/usr/include/alsa/version.h' (file installed with libasound2-dev),
    There is A line:

    #define SND_LIB_VERSION_STR "1.1.3"

    This next statement prints the version string. */

    printf("Alsa Version: %s\n", SND_LIB_VERSION_STR);

    exit(0);
}
