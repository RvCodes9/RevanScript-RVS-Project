rm -f RevanScript
if gcc -static -std=c99 -O2 -o bin/RevanScript src/main.c src/rvsio.c src/rvsctl.c src/rvsmem.c src/rvsbuf.c src/rvsflg.c src/rvsprs.c; then
    strip bin/RevanScript
    echo Successful Executable!!!
else
    echo No Executable!!!
fi
