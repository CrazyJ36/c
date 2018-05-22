After c programs are compiled on one processor they
cannot run on another until the "file.c" is compiled
on the other machine.
While using different platforms make sure there in the
right directories here, aarch64 (64 bit arm), linux, windows.


Windows: 
- see https://msdn.microsoft.com/en-us/library/bb384838.aspx
and c/SizeOfInt
- mingw tools enable compiling on windows to.

With Visual Studio Build Tools installed:
-Open Developer Command Prompt for VS
-to compile:
cl filename.c
outputs to filename.exe (filename.out is unneeded).

- Naming:
If compiling multiple files into one, the first filename is used
for the final program name. use the /out:programname after filename.c flag to change.

- Warning Levels:
To catch more programming mistakes, use /W4 or /W3 before filename.c

- Help:
use cl /? for more options.

Linux:
- Install the C compiler: 

GCC:
sudo apt-get install gcc

Or for bigger development:
sudo apt-get install build-essential manpages-dev

- Compile program.c:
gcc program-source-code.c -o executable-output-file-name

gcc, cc, and make all call the c compiler.
though 'make program.c' auto names the executable the name of the source code.


Example c program:

# include <stdio.h>
int main()
{
 printf("hello world\n");
}
