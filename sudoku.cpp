#include <vector>
#include <iostream>

#include "./sudoku_grid.h"

int main(int argc, char const *argv[]) {
  std::vector<std::vector<int>> grid = {
    {8, 0, 7, 0, 0, 4, 0, 0, 9},
    {1, 0, 9, 8, 0, 2, 3, 0, 7},
    {0, 3, 5, 0, 0, 7, 4, 0, 6},
    {6, 0, 4, 7, 8, 0, 9, 3, 0},
    {9, 0, 3, 0, 0, 1, 0, 7, 0},
    {7, 8, 0, 0, 0, 3, 1, 4, 0},
    {0, 7, 1, 4, 0, 9, 8, 0, 3},
    {4, 2, 0, 3, 7, 6, 0, 9, 1},
    {3, 9, 0, 1, 0, 8, 7, 0, 4},
  };

  SudokuGrid g = SudokuGrid(grid);

  std::cout << g.to_string();

  return 0;
}
