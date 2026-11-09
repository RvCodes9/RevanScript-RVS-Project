rm -f ../bin/clang/RevanScript
# CORE -- main.c
if clang -std=c99 -O2 -c ../src/main.c -o ../objects/clang/main.o; then
	echo "Successful [main.o] object file!!!"
else
	echo "Failed [main.o] object file!!!"
fi
# CORE -- rvsbuf.c
if clang -std=c99 -O2 -c ../src/rvsbuf.c -o ../objects/clang/rvsbuf.o; then
	echo "Successful [rvsbuf.o] object file!!!"
else
	echo "Failed [rvsbuf.o] object file!!!"
fi
# CORE -- rvsctl.c
if clang -std=c99 -O2 -c ../src/rvsctl.c -o ../objects/clang/rvsctl.o; then
	echo "Successful [rvsctl.o] object file!!!"
else
	echo "Failed [rvsctl.o] object file!!!"
fi
# CORE -- rvsexp.c
if clang -std=c99 -O2 -c ../src/rvsexp.c -o ../objects/clang/rvsexp.o; then
	echo "Successful [rvsexp.o] object file!!!"
else
	echo "Failed [rvsexp.o] object file!!!"
fi
# CORE -- rvsflg.c
if clang -std=c99 -O2 -c ../src/rvsflg.c -o ../objects/clang/rvsflg.o; then
	echo "Successful [rvsflg.o] object file!!!"
else
	echo "Failed [rvsflg.o] object file!!!"
fi
# CORE -- rvsio.c
if clang -std=c99 -O2 -c ../src/rvsio.c -o ../objects/clang/rvsio.o; then
	echo "Successful [rvsio.o] object file!!!"
else
	echo "Failed [rvsio.o] object file!!!"
fi
# CORE -- rvslgc.c
if clang -std=c99 -O2 -c ../src/rvslgc.c -o ../objects/clang/rvslgc.o; then
	echo "Successful [rvslgc.o] object file!!!"
else
	echo "Failed [rvslgc.o] object file!!!"
fi
# CORE -- rvsmem.c
if clang -std=c99 -O2 -c ../src/rvsmem.c -o ../objects/clang/rvsmem.o; then
	echo "Successful [rvsmem.o] object file!!!"
else
	echo "Failed [rvsmem.o] object file!!!"
fi
# CORE -- rvsmth.c
if clang -std=c99 -O2 -c ../src/rvsmth.c -o ../objects/clang/rvsmth.o; then
	echo "Successful [rvsmth.o] object file!!!"
else
	echo "Failed [rvsmth.o] object file!!!"
fi
# CORE -- rvsprs.c
if clang -std=c99 -O2 -c ../src/rvsprs.c -o ../objects/clang/rvsprs.o; then
	echo "Successful [rvsprs.o] object file!!!"
else
	echo "Failed [rvsprs.o] object file!!!"
fi
# CORE -- rvsstd.c
if clang -std=c99 -O2 -c ../src/rvsstd.c -o ../objects/clang/rvsstd.o; then
	echo "Successful [rvsstd.o] object file!!!"
else
	echo "Failed [rvsstd.o] object file!!!"
fi
# CORE -- rvstbl.c
if clang -std=c99 -O2 -c ../src/rvstbl.c -o ../objects/clang/rvstbl.o; then
	echo "Successful [rvstbl.o] object file!!!"
else
	echo "Failed [rvstbl.o] object file!!!"
fi
# CORE -- rvskey.c
if clang -std=c99 -O2 -c ../src/rvskey.c -o ../objects/clang/rvskey.o; then
	echo "Successful [rvskey.o] object file!!!"
else
	echo "Failed [rvskey.o] object file!!!"
fi
# CORE -- rvsarr.c
if clang -std=c99 -O2 -c ../src/rvsarr.c -o ../objects/clang/rvsarr.o; then
	echo "Successful [rvsarr.o] object file!!!"
else
	echo "Failed [rvsarr.o] object file!!!"
fi
# CORE -- rvsmtx.c
if clang -std=c99 -O2 -c ../src/rvsmtx.c -o ../objects/clang/rvsmtx.o; then
	echo "Successful [rvsmtx.o] object file!!!"
else
	echo "Failed [rvsmtx.o] object file!!!"
fi
# CORE -- rvswin.c
if clang -std=c99 -O2 -c ../src/rvswin.c -o ../objects/clang/rvswin.o; then
	echo "Successful [rvswin.o] object file!!!"
else
	echo "Failed [rvswin.o] object file!!!"
fi
# SUBSYSTEM -- menu.c
if clang -std=c99 -O2 -c ../src/games/menu.c -o ../objects/clang/games/menu.o; then
	echo "Successful [Subsystem][games/menu.o] object file!!!"
else
	echo "Failed [Subsystem][games/menu.o] object file!!!"
fi
# SUBSYSTEM -- guess-the-number/init.c
if clang -std=c99 -O2 -c ../src/games/console/guess-the-number/init.c -o ../objects/clang/games/console/guess-the-number/init.o; then
	echo "Successful [Subsystem][games/console/guess-the-number/init.o] object file!!!"
else
	echo "Failed [Subsystem][games/console/guess-the-number/init.o] object file!!!"
fi
# SUBSYSTEM -- guess-the-number/game.c
if clang -std=c99 -O2 -c ../src/games/console/guess-the-number/game.c -o ../objects/clang/games/console/guess-the-number/game.o; then
	echo "Successful [Subsystem][games/console/guess-the-number/game.o] object file!!!"
else
	echo "Failed [Subsystem][games/console/guess-the-number/game.o] object file!!!"
fi
# SUBSYSTEM -- tic-tac-toe/init.c
if clang -std=c99 -O2 -c ../src/games/console/tic-tac-toe/init.c -o ../objects/clang/games/console/tic-tac-toe/init.o; then
	echo "Successful [Subsystem][games/console/tic-tac-toe/init.o] object file!!!"
else
	echo "Failed [Subsystem][games/console/tic-tac-toe/init.o] object file!!!"
fi
# SUBSYSTEM -- minesweeper/init.c
if clang -std=c99 -O2 -c ../src/games/console/minesweeper/init.c -o ../objects/clang/games/console/minesweeper/init.o; then
	echo "Successful [Subsystem][games/console/minesweeper/init.o] object file!!!"
else
	echo "Failed [Subsystem][games/console/minesweeper/init.o] object file!!!"
fi
# COMPILE -- EXECUTABLE
if clang -o ../bin/clang/RevanScript ../objects/clang/*.o ../objects/clang/games/*.o ../objects/clang/games/console/guess-the-number/*.o ../objects/clang/games/console/tic-tac-toe/*.o ../objects/clang/games/console/minesweeper/*.o; then
    strip ../bin/clang/RevanScript
    echo "Successful Executable!!!"
else
    echo "Failed Executable!!!"
fi