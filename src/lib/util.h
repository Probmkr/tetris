#ifndef CLEAR_H
#define CLEAR_H
#include <string>
#include <random>

using namespace std;
using w_size = unsigned short;

const w_size min_w = 74;
const w_size left_side_w = 40;
const w_size game_w = 20;
const w_size game_h = 20;
const w_size wall_w = 2;
const w_size wall_h = 1;
const w_size right_side_w = 40;
const w_size gap_w = 5;
const w_size min_h = game_h + wall_h * 2;
const w_size d_pos[2] = {3, 3};
void Clear(bool flush = true);

template <class T>
void Sleep(T);

void get_ws(w_size &, w_size &);

void display(bool game[game_h][game_w / 2]);

class Block
{
  w_size pos[2];
  bool *game[game_h];
  unsigned short dir;
  mt19937 mt;
  uniform_int_distribution<> rand7;
  bool pattern[4][4][4];

  int get_rand();
  void set_pattern(const bool pattern[4][4][4]);
  void render();

public:
  Block(bool game[game_h][game_w / 2]);
  void set_block(int type = -1);
};

#endif
