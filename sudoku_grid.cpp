#include "./sudoku_grid.h"
#include <vector>

SudokuGrid::SudokuGrid(std::vector<std::vector<int>> grid) {
  _grid = grid;
  refresh();
}

bool SudokuGrid::won() {
  return (_incorrect_points.size() == 0) && (empty_spots == 0);
}

void SudokuGrid::refresh() {

}

void move(int num, size_t row, size_t col) {

}

void move_cursor(char direction) {
  
} // 'u' 'd' 'l' 'r'
