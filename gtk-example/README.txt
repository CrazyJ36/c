compile:
gcc `pkg-config --cflags gtk+-3.0` -o gtk-example gtk-example.c `pkg-config --libs gtk+-3.0`


