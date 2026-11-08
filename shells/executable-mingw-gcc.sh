rm -f ../bin/mingw-gcc/RevanScript.exe
# CORE -- main.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/main.c -o ../objects/mingw-gcc/main.o; then
	echo "Successful [main.o] object file!!!"
else
	echo "Failed [main.o] object file!!!"
fi
# CORE -- rvsbuf.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/rvsbuf.c -o ../objects/mingw-gcc/rvsbuf.o; then
	echo "Successful [rvsbuf.o] object file!!!"
else
	echo "Failed [rvsbuf.o] object file!!!"
fi
# CORE -- rvsctl.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/rvsctl.c -o ../objects/mingw-gcc/rvsctl.o; then
	echo "Successful [rvsctl.o] object file!!!"
else
	echo "Failed [rvsctl.o] object file!!!"
fi
# CORE -- rvsexp.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/rvsexp.c -o ../objects/mingw-gcc/rvsexp.o; then
	echo "Successful [rvsexp.o] object file!!!"
else
	echo "Failed [rvsexp.o] object file!!!"
fi
# CORE -- rvsflg.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/rvsflg.c -o ../objects/mingw-gcc/rvsflg.o; then
	echo "Successful [rvsflg.o] object file!!!"
else
	echo "Failed [rvsflg.o] object file!!!"
fi
# CORE -- rvsio.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/rvsio.c -o ../objects/mingw-gcc/rvsio.o; then
	echo "Successful [rvsio.o] object file!!!"
else
	echo "Failed [rvsio.o] object file!!!"
fi
# CORE -- rvslgc.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/rvslgc.c -o ../objects/mingw-gcc/rvslgc.o; then
	echo "Successful [rvslgc.o] object file!!!"
else
	echo "Failed [rvslgc.o] object file!!!"
fi
# CORE -- rvsmem.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/rvsmem.c -o ../objects/mingw-gcc/rvsmem.o; then
	echo "Successful [rvsmem.o] object file!!!"
else
	echo "Failed [rvsmem.o] object file!!!"
fi
# CORE -- rvsmth.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/rvsmth.c -o ../objects/mingw-gcc/rvsmth.o; then
	echo "Successful [rvsmth.o] object file!!!"
else
	echo "Failed [rvsmth.o] object file!!!"
fi
# CORE -- rvsprs.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/rvsprs.c -o ../objects/mingw-gcc/rvsprs.o; then
	echo "Successful [rvsprs.o] object file!!!"
else
	echo "Failed [rvsprs.o] object file!!!"
fi
# CORE -- rvsstd.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/rvsstd.c -o ../objects/mingw-gcc/rvsstd.o; then
	echo "Successful [rvsstd.o] object file!!!"
else
	echo "Failed [rvsstd.o] object file!!!"
fi
# CORE -- rvstbl.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/rvstbl.c -o ../objects/mingw-gcc/rvstbl.o; then
	echo "Successful [rvstbl.o] object file!!!"
else
	echo "Failed [rvstbl.o] object file!!!"
fi
# CORE -- rvskey.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/rvskey.c -o ../objects/mingw-gcc/rvskey.o; then
	echo "Successful [rvskey.o] object file!!!"
else
	echo "Failed [rvskey.o] object file!!!"
fi
# CORE -- rvsarr.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/rvsarr.c -o ../objects/mingw-gcc/rvsarr.o; then
	echo "Successful [rvsarr.o] object file!!!"
else
	echo "Failed [rvsarr.o] object file!!!"
fi
# CORE -- rvsmtx.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/rvsmtx.c -o ../objects/mingw-gcc/rvsmtx.o; then
	echo "Successful [rvsmtx.o] object file!!!"
else
	echo "Failed [rvsmtx.o] object file!!!"
fi
# SUBSYSTEM -- menu.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/games/menu.c -o ../objects/mingw-gcc/games/menu.o; then
	echo "Successful [Subsystem][games/menu.o] object file!!!"
else
	echo "Failed [Subsystem][games/menu.o] object file!!!"
fi
# SUBSYSTEM -- guess-the-number/init.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/games/console/guess-the-number/init.c -o ../objects/mingw-gcc/games/console/guess-the-number/init.o; then
	echo "Successful [Subsystem][games/console/guess-the-number/init.o] object file!!!"
else
	echo "Failed [Subsystem][games/console/guess-the-number/init.o] object file!!!"
fi
# SUBSYSTEM -- guess-the-number/game.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/games/console/guess-the-number/game.c -o ../objects/mingw-gcc/games/console/guess-the-number/game.o; then
	echo "Successful [Subsystem][games/console/guess-the-number/game.o] object file!!!"
else
	echo "Failed [Subsystem][games/console/guess-the-number/game.o] object file!!!"
fi
# SUBSYSTEM -- tic-tac-toe/init.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/games/console/tic-tac-toe/init.c -o ../objects/mingw-gcc/games/console/tic-tac-toe/init.o; then
	echo "Successful [Subsystem][games/console/tic-tac-toe/init.o] object file!!!"
else
	echo "Failed [Subsystem][games/console/tic-tac-toe/init.o] object file!!!"
fi
# SUBSYSTEM -- minesweeper/init.c
if x86_64-w64-mingw32-gcc -std=c99 -O2 -c ../src/games/console/minesweeper/init.c -o ../objects/mingw-gcc/games/console/minesweeper/init.o; then
	echo "Successful [Subsystem][games/console/minesweeper/init.o] object file!!!"
else
	echo "Failed [Subsystem][games/console/minesweeper/init.o] object file!!!"
fi
# COMPILE -- EXECUTABLE
if x86_64-w64-mingw32-gcc -o ../bin/mingw-gcc/RevanScript.exe ../objects/mingw-gcc/*.o ../objects/mingw-gcc/games/*.o ../objects/mingw-gcc/games/console/guess-the-number/*.o ../objects/mingw-gcc/games/console/tic-tac-toe/*.o ../objects/mingw-gcc/games/console/minesweeper/*.o; then
    strip ../bin/mingw-gcc/RevanScript.exe
    echo "Successful Executable!!!"
else
    echo "Failed Executable!!!"
fi
