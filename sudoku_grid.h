#ifndef SUDOKU_GRID_H
#define SUDOKU_GRID_H 1

#include <vector>

class SudokuGrid {
  std::vector<std::vector<int>> _grid;

  std::vector<std::vector<int>> _incorrect_points;
  size_t empty_spots;

  SudokuGrid(std::vector<std::vector<int>> grid);

  bool won();

  void move(int num, size_t row, size_t col);

  void move_cursor(char direction); // 'u' 'd' 'l' 'r'

  void refresh();
};

#endif
