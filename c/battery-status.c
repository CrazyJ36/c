/* File: battery-status.c
   Author: CrazyJ36
   Description:
   Uses info from /sys/class/power_supply/BAT1
   to show the current state of laptop battery.
   May not work under chroot or linux distros like Android.
   Only when the system has the above directory with
   'capacity' and 'status' files.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int CAPLEN = 4;
    int STATLEN = 13;
    char *capacityFile = "/sys/class/power_supply/BAT1/capacity";
    char *statusFile = "/sys/class/power_supply/BAT1/status";
    FILE *capacityFilePointer;
    FILE *statusFilePointer;
    char capStr[CAPLEN];
    char statStr[STATLEN];
    capacityFilePointer = fopen(capacityFile, "r");
    statusFilePointer = fopen(statusFile, "r");
    if (capacityFilePointer == NULL || statusFilePointer == NULL) {
        printf("Known battery status files don't exist on this system. Exiting...\n");
  	exit(1);
    }
    int capFileGetRet = (int) fgets(capStr, CAPLEN, capacityFilePointer);
    int statFileGetRet = (int) fgets(statStr, STATLEN, statusFilePointer);
    if (capFileGetRet != EOF || statFileGetRet != EOF) {
        printf("Battery Percentage: %s\n", capStr);
        printf("Charging or Discharging: %s\n", statStr);
    } else {
          printf("Getting battery capacity or status failed. Exiting...\n");
          exit(1);
    }
    fclose(capacityFilePointer);
    fclose(statusFilePointer);
    exit(0);
}
