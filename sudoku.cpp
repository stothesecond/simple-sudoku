#include <vector>
#include <limits>
#include <iostream>
#include <fstream>
#include <sstream>

#include "./sudoku_grid.h"

std::string getFile(std::string fname) {
  std::ifstream file_main_menu (fname, std::ifstream::binary);

  if (file_main_menu) {
    // get length of file:
    file_main_menu.seekg(0, file_main_menu.end);
    int length = file_main_menu.tellg();

    file_main_menu.seekg(0, file_main_menu.beg);
    
    char * buffer = new char [length];

    file_main_menu.read(buffer, length);

    file_main_menu.close();

    std::string ans = buffer;

    delete[] buffer;

    return ans;
  }
  std::stringstream ansStream;
  ansStream << "-- error - could not read file [" << fname << "] --";
  return ansStream.str();
}

// press enter to continue
// https://stackoverflow.com/a/903230
void promptEnter() {
  std::cout << "Press ENTER to continue...";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int promptChoice(int u_bound = -1) {
  int ans;
  for (;;) {
    std::cout << "Select an option: ";
    if (std::cin >> ans) {
      if (((u_bound == -1) || (u_bound >= ans)) && (ans > 0)) {
        break;
      }
    }
    std::cout << "Please select a valid option!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
  }
  return ans;
}

void showWrongInputMessage() {
  // show the wrong input
  std::cout << getFile("res/wrong_input.txt") << std::endl;
  std::cout << getFile("res/input_instructions.txt") << std::endl;
}

void promptAction(SudokuGrid &grid) {
  std::string act;
  int row, col, num;

  for (;;) {
    std::cout << "Input a board action: ";
    std::cin >> act;

    if (act == "ins") {
      if (std::cin >> row && std::cin >> col && std::cin >> num) {
        grid.insert(num, row, col);
        break;
      } else {
        std::cout << std::endl;
        showWrongInputMessage();
        std::cout << std::endl;
      }
    } else if (act == "rem") {
      if (std::cin >> row && std::cin >> col) {
        grid.remove(row, col);
        break;
      } else {
        std::cout << std::endl;
        showWrongInputMessage();
        std::cout << std::endl;
      }
    } else if (act == "quit") {
      grid.quit();
      break;
    } else {
      std::cout << std::endl;
      showWrongInputMessage();
      std::cout << std::endl;
    }
  }
}

void showHowToPlay() {
  // show how to play
  std::cout << getFile("res/how_to_play.txt") << std::endl;


  promptEnter();
}

void showQuitMessage() {
  // show the quit message
  std::cout << getFile("res/quit.txt") << std::endl;
}

void showWinMessage() {
  // show the win message
  std::cout << getFile("res/win.txt") << std::endl;

  promptEnter();
}


int showMainMenu() {
  // show the main menu
  std::cout << getFile("res/main_menu.txt") << std::endl;

  return promptChoice(3);
}

void startGame() {
  std::vector<std::vector<int>> _grid_raw = {
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

  SudokuGrid grid = SudokuGrid(_grid_raw);
  
  while (!grid.won() && !grid.didQuit()) {
    std::cout << grid.to_string() << std::endl;  
    std::cout << getFile("res/input_instructions.txt") << std::endl;
    promptAction(grid);
  }
}

int main(int argc, char const *argv[]) {
  // std::cout << g.to_string();

  bool quit = false;
  int choice = -1;
  while (!quit) {
    choice = showMainMenu();
    switch(choice) {
      case 1:
        startGame();
        continue;
      case 2:
        showHowToPlay();
        continue;
      case 3:
        showQuitMessage();
        quit = true;
        continue;
    }
    break;
  }

  return 0;
}

