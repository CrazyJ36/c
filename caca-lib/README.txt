# Requires:
sudo apt-get install pkg-config
# To Compile program using libcaca:
gcc `pkg-config --libs --cflags caca` prog.c -o prog
