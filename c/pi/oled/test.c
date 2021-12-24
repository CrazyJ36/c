//
// oled test program
//
// Written by Larry Bank
// Copyright 2017 BitBank Software, Inc. All Rights Reserved.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//    http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//===========================================================================

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "oled96.h"

int main(int argc, char *argv[])
{
int i, iChannel;
int iOLEDAddr = 0x3c; // typical address; it can also be 0x3d
int iOLEDType = OLED_128x32; // Change this for your specific display
int bFlip = 0, bInvert = 0;

	i = -1;
	iChannel = -1;
	while (i != 0 && iChannel < 2) // try I2C channel 0 through 2
	{
		iChannel++;
		i=oledInit(iChannel, iOLEDAddr, iOLEDType, bFlip, bInvert);
	}
	if (i == 0)
	{
		printf("Successfully opened I2C bus %d\n", iChannel);
		oledFill(0); // fill with black

                // oledWriteString(x_pos, y_pos, string, size) is based on the start point of spaces for insertion
                // ofcharacters, so x axis can be 0-15(16 characters display). Shows from left to right.
                // y signifies 4 horizontal rows, 0-3 for normal font size..
                // font sizes: FONT_SMALL - 8x8, FONT_BIG - 16x24, FONT_SMALL - 6x8,
                //changing sizes can cause moving of characters into unwanted places.

		oledWriteString(7, 0,"a", FONT_NORMAL);
                oledWriteString(7, 1, "b", FONT_NORMAL);
                oledWriteString(7, 2, "c", FONT_NORMAL);
                oledWriteString(7, 3, "d", FONT_NORMAL);

                // oledSetPixel(x_pos, y_pos, color)
                // these two function calls will show A pixel in the top left and bottom right.
                oledSetPixel(0,0, 1);
                oledSetPixel(125, 30, 1);

                // lines
		/*for (i=0; i<16; i++)
		{
			oledSetPixel(i, 16+i, 1);
			oledSetPixel(127-i, 16+i, 1);
		}*/

		printf("Press ENTER to quit\n");
		getchar();
		oledShutdown();
	}
	else
	{
		printf("Unable to initialize I2C bus 0-2, check solder and verify the device address.\n");
	}
   return 0;
} /* main() */
