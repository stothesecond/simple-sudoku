#include "sudoku_grid.h"

#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>

void SudokuGrid::refresh() {
  _incorrect_squares.clear();
  _empty_spots = 0;

  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (_grid[i][j] == 0) {
        ++_empty_spots;
      } else {
        // check correctness of _grid[i][j].
        // add to _incorrect_squares.
      }
    }
  }
}

SudokuGrid::SudokuGrid(std::vector<std::vector<int>> grid) {
  _starting_grid = grid;
  _grid = grid;
  refresh();
}

bool SudokuGrid::won() {
  return (_incorrect_squares.size() == 0) && (_empty_spots == 0);
}

void SudokuGrid::insert(int num, size_t row, size_t col) {
  // ins [row] [col] [number] 
}

void SudokuGrid::remove(size_t row, size_t col) {
  // rem [row] [col]
}

std::string SudokuGrid::to_string() {
  std::stringstream output;

  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {

      if (_starting_grid[i][j] == 0) {
        output << '(' << _grid[i][j] << ')';
      } else {
        output << '[' << _starting_grid[i][j] << ']';
      }


      if (j % 3 == 2) {
          output << "  ";
      }
    }
    if (i % 3 == 2) {
      output << '\n';
    }
    if (i < 8) output << '\n';
  }
  return output.str();
}