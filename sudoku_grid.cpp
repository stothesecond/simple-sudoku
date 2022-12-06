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
      } else if (_starting_grid[i][j]) {
        // check correctness of _grid[i][j].
        // add to _incorrect_squares.
        
      }
    }
  }
}

SudokuGrid::SudokuGrid(std::vector<std::vector<int>> grid) {
  _starting_grid = grid;
  _grid = grid;
  _quit = false;
  refresh();
}

bool SudokuGrid::won() {
  return (_incorrect_squares.size() == 0) && (_empty_spots == 0);
}

void SudokuGrid::quit() {
  _quit = true;
}

bool SudokuGrid::didQuit() {
  return _quit;
}


// returns 0 if successful and 1 if unsuccessful
int SudokuGrid::insert(int num, size_t row, size_t col) {
  // ins [row] [col] [number]
  // make sure you can't remove or insert that was there before you started

  if ((_starting_grid[9 - row][col - 1] != 0) || (num < 1) || (num > 9)) {
    return 1;
  }

  _grid[9 - row][col - 1] = num;
  return 0;
}


// returns 0 if successful and 1 if unsuccessful
int SudokuGrid::remove(size_t row, size_t col) {
  // rem [row] [col]
  if (_starting_grid[9 - row][col - 1] != 0) {
    return 1;
  }

  _grid[9 - row][col - 1] = 0;
  return 0;
}

std::string SudokuGrid::to_string() {
  std::stringstream output;

  for (int i = 0; i < 9; ++i) {
    output << 9 - i << " || ";
    for (int j = 0; j < 9; ++j) {

      if (_starting_grid[i][j] == 0) {
        bool incorrect = false;
        for (auto k = _incorrect_squares.begin(); k != _incorrect_squares.end(); ++k) {
          if ((*k)[0] == i && (*k)[1] == j) {
            incorrect = true;
            break;
          }
        }
        if (incorrect) {
          output << '>' << _grid[i][j] << '<';
        } else {
          output << '(' << _grid[i][j] << ')';
        }
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
  output << "     ===============================\n";
  output << "      1  2  3    4  5  6    7  8  9\n";
  return output.str();
}
