Not working on toshiba x86 need real libcaca package
works in termux android.
# Requires:
sudo apt-get install pkg-config
# To Compile program using libcaca (pkg-config statement must be after specifying file):
gcc prog.c `pkg-config --libs --cflags caca` 


