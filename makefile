sudoku: sudoku.o
	g++ -o sudoku sudoku.o


sudoku.o:
	g++ -o sudoku.o -c main.cpp
