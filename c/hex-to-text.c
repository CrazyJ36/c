/* The unsigned char text[] below was converted automatically from
   A text file that contained text that this program outputs to terminal.
   The utility used was downloaded from Roadkil.net and called 'Roadkil's Data Byte'.
   The utility itself can convert any file to hex using C style header.
*/
#include <stdio.h>

// The contains hex version of text to be printed.
unsigned char text[] =
{
0x54,0x68,0x69,0x73,0x20,0x69,0x73,0x20,0x74,0x65,0x78,0x74,0x20,0x74,0x6F,0x20
,0x62,0x65,0x20,0x63,0x6F,0x6E,0x76,0x65,0x72,0x74,0x65,0x64,0x20,0x74,0x6F,0x20
,0x68,0x65,0x78,0x00
};

int main() {
	printf("%s\n", text);
	return(0);
}
