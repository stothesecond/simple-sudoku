sudoku: build/sudoku.o build/sudoku_grid.o
	g++ -o sudoku build/sudoku.o build/sudoku_grid.o

build/sudoku.o: sudoku.cpp sudoku_grid.h
	g++ -o build/sudoku.o -c sudoku.cpp

build/sudoku_grid.o: sudoku_grid.cpp sudoku_grid.h
	g++ -o build/sudoku_grid.o -c sudoku_grid.cpp