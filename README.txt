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
