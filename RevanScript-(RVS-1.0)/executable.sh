rm -f RevanScript
if gcc -std=c99 -O2 -o bin/RevanScript src/main.c src/rvsio.c src/rvsctl.c src/rvsmem.c src/rvsbuf.c src/rvsflg.c; then
    echo Successful Executable!!!
else
    echo No Executable!!!
fi
