rm -f RevanScript
if gcc -std=c99 -O2 -o RevanScript main.c rvsio.c rvsctl.c; then
    echo Successful Executable!!!
else
    echo No Executable!!!
fi
