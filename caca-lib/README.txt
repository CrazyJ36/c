Not working on toshiba x86 need real libcaca package
works in termux android.
# Requires:
sudo apt-get install pkg-config
# To Compile program using libcaca:
gcc `pkg-config --libs --cflags caca` prog.c -o prog


