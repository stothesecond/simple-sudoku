#include <vector>
#include <iostream>
int main(int argc, char const *argv[]) {
  std::vector<std::vector<int>> grid;

  for (int i = 0; i < 9; ++i) {
    grid.push_back({});
    for (int j = 0; j < 9; ++j) {
      grid[i].push_back(0);
    }
  }

  // print_grid(grid);
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      std::cout << '[';

      if (grid[i][j] == 0) {
          std::cout << ' ';
      } else {
          std::cout << grid[i][j];
      }

      std::cout << ']';


      if (j % 3 == 2) {
          std::cout << "  ";
      }
    }
    if (i % 3 == 2) {
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }


  return 0;
}
