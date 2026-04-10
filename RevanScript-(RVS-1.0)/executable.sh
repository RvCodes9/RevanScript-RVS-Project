rm -f RevanScript
if gcc -std=c99 -O2 -o bin/RevanScript scr/main.c scr/rvsio.c scr/rvsctl.c scr/rvsmem.c scr/rvsbuf.c; then
    echo Successful Executable!!!
else
    echo No Executable!!!
fi
