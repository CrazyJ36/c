Install:
Download from http://freeglut.sourceforge.net/ 
Copy extracted files to C:\Program Files\Common Files\MSVC\freeglut
Copy bin/x64/freeglut.dll to C:\Windows

opengl-test is from https://www.c-sharpcorner.com/UploadFile/f5a10c/getting-started-with-opengl-in-visual-cpp/.
compile with: > cl opengl-test.c /link "C:\Program Files\Common Files\MSVC\freeglut\lib\x64\freeglut.lib"
