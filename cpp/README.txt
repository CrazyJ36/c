WINDOWS:
Check mingw for windows, it's A compiler that doesn't require A whole Visual Studio
make new file "name.cpp"
code example:

#include <iostream>  
using namespace std;  
void main()  
{  
    cout << "Hello, world, from Visual C++!" << endl;  
}

Use Developer Command Prompt for Visual Studio.
To compile, run at prompt:

cl /EHsc name.cpp

This will generate an uneeded "name.obj"(contains compiled code), and the program name.exe.


cl - the c++ compiler for windows vs
g++ - the c++ compiler for linux

-the windows option "/EHsc" shown instructs the compiler the enable C++ exeption handling.

- 'cl' options /w3 /w4 etc. are for warning levels to catch programming mistakes.

- the command 'cl /EHsc file1.cpp file2.cpp' -ccompile multiple source files.
 this causes the program name to be the first file (file1.exe) to change the program name while including several  files, use: 'cl /EHsc file1.cpp file2.cpp /link /out:program.exe'.

- the '/link option uses the linker to link compiled object files and libs into DLL.



LINUX:
- example code:

#include "iostream"
int main(void)
{
  printf("hello world");
  return 0;
}

- Compiler:
sudo apt-get install g++

g++ program.cpp -o program
