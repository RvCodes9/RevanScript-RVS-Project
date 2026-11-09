rm -f ../bin/gcc/RevanScript
# CORE -- main.c
if gcc -std=c99 -O2 -c ../src/main.c -o ../objects/gcc/main.o; then
	echo "Successful [main.o] object file!!!"
else
	echo "Failed [main.o] object file!!!"
fi
# CORE -- rvsbuf.c
if gcc -std=c99 -O2 -c ../src/rvsbuf.c -o ../objects/gcc/rvsbuf.o; then
	echo "Successful [rvsbuf.o] object file!!!"
else
	echo "Failed [rvsbuf.o] object file!!!"
fi
# CORE -- rvsctl.c
if gcc -std=c99 -O2 -c ../src/rvsctl.c -o ../objects/gcc/rvsctl.o; then
	echo "Successful [rvsctl.o] object file!!!"
else
	echo "Failed [rvsctl.o] object file!!!"
fi
# CORE -- rvsexp.c
if gcc -std=c99 -O2 -c ../src/rvsexp.c -o ../objects/gcc/rvsexp.o; then
	echo "Successful [rvsexp.o] object file!!!"
else
	echo "Failed [rvsexp.o] object file!!!"
fi
# CORE -- rvsflg.c
if gcc -std=c99 -O2 -c ../src/rvsflg.c -o ../objects/gcc/rvsflg.o; then
	echo "Successful [rvsflg.o] object file!!!"
else
	echo "Failed [rvsflg.o] object file!!!"
fi
# CORE -- rvsio.c
if gcc -std=c99 -O2 -c ../src/rvsio.c -o ../objects/gcc/rvsio.o; then
	echo "Successful [rvsio.o] object file!!!"
else
	echo "Failed [rvsio.o] object file!!!"
fi
# CORE -- rvslgc.c
if gcc -std=c99 -O2 -c ../src/rvslgc.c -o ../objects/gcc/rvslgc.o; then
	echo "Successful [rvslgc.o] object file!!!"
else
	echo "Failed [rvslgc.o] object file!!!"
fi
# CORE -- rvsmem.c
if gcc -std=c99 -O2 -c ../src/rvsmem.c -o ../objects/gcc/rvsmem.o; then
	echo "Successful [rvsmem.o] object file!!!"
else
	echo "Failed [rvsmem.o] object file!!!"
fi
# CORE -- rvsmth.c
if gcc -std=c99 -O2 -c ../src/rvsmth.c -o ../objects/gcc/rvsmth.o; then
	echo "Successful [rvsmth.o] object file!!!"
else
	echo "Failed [rvsmth.o] object file!!!"
fi
# CORE -- rvsprs.c
if gcc -std=c99 -O2 -c ../src/rvsprs.c -o ../objects/gcc/rvsprs.o; then
	echo "Successful [rvsprs.o] object file!!!"
else
	echo "Failed [rvsprs.o] object file!!!"
fi
# CORE -- rvsstd.c
if gcc -std=c99 -O2 -c ../src/rvsstd.c -o ../objects/gcc/rvsstd.o; then
	echo "Successful [rvsstd.o] object file!!!"
else
	echo "Failed [rvsstd.o] object file!!!"
fi
# CORE -- rvstbl.c
if gcc -std=c99 -O2 -c ../src/rvstbl.c -o ../objects/gcc/rvstbl.o; then
	echo "Successful [rvstbl.o] object file!!!"
else
	echo "Failed [rvstbl.o] object file!!!"
fi
# CORE -- rvskey.c
if gcc -std=c99 -O2 -c ../src/rvskey.c -o ../objects/gcc/rvskey.o; then
	echo "Successful [rvskey.o] object file!!!"
else
	echo "Failed [rvskey.o] object file!!!"
fi
# CORE -- rvsarr.c
if gcc -std=c99 -O2 -c ../src/rvsarr.c -o ../objects/gcc/rvsarr.o; then
	echo "Successful [rvsarr.o] object file!!!"
else
	echo "Failed [rvsarr.o] object file!!!"
fi
# CORE -- rvsmtx.c
if gcc -std=c99 -O2 -c ../src/rvsmtx.c -o ../objects/gcc/rvsmtx.o; then
	echo "Successful [rvsmtx.o] object file!!!"
else
	echo "Failed [rvsmtx.o] object file!!!"
fi
# CORE -- rvswin.c
if gcc -std=c99 -O2 -c ../src/rvswin.c -o ../objects/gcc/rvswin.o; then
	echo "Successful [rvswin.o] object file!!!"
else
	echo "Failed [rvswin.o] object file!!!"
fi
# SUBSYSTEM -- menu.c
if gcc -std=c99 -O2 -c ../src/games/menu.c -o ../objects/gcc/games/menu.o; then
	echo "Successful [Subsystem][games/menu.o] object file!!!"
else
	echo "Failed [Subsystem][games/menu.o] object file!!!"
fi
# SUBSYSTEM -- guess-the-number/init.c
if gcc -std=c99 -O2 -c ../src/games/console/guess-the-number/init.c -o ../objects/gcc/games/console/guess-the-number/init.o; then
	echo "Successful [Subsystem][games/console/guess-the-number/init.o] object file!!!"
else
	echo "Failed [Subsystem][games/console/guess-the-number/init.o] object file!!!"
fi
# SUBSYSTEM -- guess-the-number/game.c
if gcc -std=c99 -O2 -c ../src/games/console/guess-the-number/game.c -o ../objects/gcc/games/console/guess-the-number/game.o; then
	echo "Successful [Subsystem][games/console/guess-the-number/game.o] object file!!!"
else
	echo "Failed [Subsystem][games/console/guess-the-number/game.o] object file!!!"
fi
# SUBSYSTEM -- tic-tac-toe/init.c
if gcc -std=c99 -O2 -c ../src/games/console/tic-tac-toe/init.c -o ../objects/gcc/games/console/tic-tac-toe/init.o; then
	echo "Successful [Subsystem][games/console/tic-tac-toe/init.o] object file!!!"
else
	echo "Failed [Subsystem][games/console/tic-tac-toe/init.o] object file!!!"
fi
# SUBSYSTEM -- minesweeper/init.c
if gcc -std=c99 -O2 -c ../src/games/console/minesweeper/init.c -o ../objects/gcc/games/console/minesweeper/init.o; then
	echo "Successful [Subsystem][games/console/minesweeper/init.o] object file!!!"
else
	echo "Failed [Subsystem][games/console/minesweeper/init.o] object file!!!"
fi
# COMPILE -- EXECUTABLE
if gcc -o ../bin/gcc/RevanScript ../objects/gcc/*.o ../objects/gcc/games/*.o ../objects/gcc/games/console/guess-the-number/*.o ../objects/gcc/games/console/tic-tac-toe/*.o ../objects/gcc/games/console/minesweeper/*.o; then
    strip ../bin/gcc/RevanScript
    echo "Successful Executable!!!"
else
    echo "Failed Executable!!!"
fi
