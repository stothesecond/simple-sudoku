sudoku: main.o sudoku_grid.o
	g++ -o sudoku main.o sudoku_grid.o

main.o: main.cpp sudoku_grid.h
	g++ -c main.cpp sudoku_grid.h

sudoku_grid.o: sudoku_grid.cpp sudoku_grid.h
	g++ -c sudoku_grid.cpp sudoku_grid.h