#include "./lib/util.h"
#include "./lib/conio.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main()
{
  bool game[game_h][game_w / 2] = {};
  // bool game[game_h][game_w / 2] = {
  //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
  //     {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
  //     {0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
  //     {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  //     {0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
  // };

  // 入力の設定
  struct termios save_settings;
  struct termios settings;
  char c;

  tcgetattr(0, &save_settings);
  settings = save_settings;

  settings.c_lflag &= ~(ECHO | ICANON); /* 入力をエコーバックしない、バッファリングしない */
  settings.c_cc[VTIME] = 0;
  settings.c_cc[VMIN] = 1;
  tcsetattr(0, TCSANOW, &settings);
  fcntl(0, F_SETFL, O_NONBLOCK); /* 標準入力からの読み込むときブロックしないようにする */

  w_size col, row;
  get_ws(col, row);
  cout << "window size: " << col << "x" << row << endl;

  Sleep(1s);
  if (col < min_w)
  {
    throw runtime_error("window col smaller than 64");
  }

  Block blk(game);

  int i = 0;
  while (true)
  {
    // cout << getchar() << endl;
    display(game);
    cout << i << endl;
    Sleep(100ms);
    ++i;
  }
  tcsetattr(0, TCSANOW, &save_settings);
  cout << "ended" << endl;
}
