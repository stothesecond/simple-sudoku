#ifndef SUDOKU_GRID_H
#define SUDOKU_GRID_H

#include <vector>
#include <cstddef>
#include <string>

class SudokuGrid {
  std::vector<std::vector<int>> _starting_grid;
  std::vector<std::vector<int>> _grid;

  std::vector<std::vector<int>> _incorrect_squares;
  size_t _empty_spots;

  void refresh();

public:
  SudokuGrid(std::vector<std::vector<int>> grid);

  bool won();

  int insert(int num, size_t row, size_t col);

  int remove(size_t row, size_t col);

  std::string to_string();
};

#endif


/*


{
  {1, 3},
  {2, 5},
  {7, 9},
  {2, 2}
}
*/
