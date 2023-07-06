#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <string>
#include "./lib/util.h"
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

const w_size min_w = 74;
const w_size left_side_w = 40;
const w_size game_w = 20;
const w_size game_h = 20;
const w_size wall_w = 2;
const w_size wall_h = 1;
const w_size right_side_w = 40;
const w_size gap_w = 5;
const w_size min_h = game_h + wall_h * 2;
short int game[game_h][game_w / 2] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 1, 1, 1, 1, 0, 1, 1, 1}};
string block = "\u2588\u2588";
string wall = "[]";
string block_fade[] = {
  "██",
  "█▊",
  "█▋",
  "█▍",
  "█▏",
  "█",
  "▊",
  "▋",
  "▍",
  "▏",
  "  "
};
string air = " .";

int main()
{
  w_size col, row;
  get_ws(col, row);
  cout << col << endl;
  if (col < min_w)
  {
    throw runtime_error("windows col smaller than 64");
  }
  for (int h = 0; h < min_h; ++h)
  {
    rep(i, left_side_w) { cout << " "; }
    if (h == 0 || h == min_h - 1)
      rep(i, game_w / 2 + wall_w) { cout << wall; }
    else
    {
      cout << wall;
      rep(i, game_w / 2) { cout << (game[h - 1][i] ? block : air); }
      cout << wall;
    }
    cout << "\n";
  }
  cout << flush;
}
