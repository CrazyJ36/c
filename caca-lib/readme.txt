Not working on toshiba x86 need real libcaca package
works in termux android.
# Requires:
sudo apt-get install pkg-config libcaca-dev libcaca0 libpng-dev libslang2-dev zlib1g-dev

# To Compile program using libcaca (pkg-config statement must be after specifying file):
gcc prog.c `pkg-config --libs --cflags caca` 


