#include "util.h"
#include "block.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <sys/ioctl.h>
#include <unistd.h>
#include <random>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
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
    "  "};
string air = " .";

void Clear(bool do_flush)
{
  cout << "\x1B[2J\x1B[H";
  if (do_flush)
  {
    cout << flush;
  }
}

template <class T>
void Sleep(T time)
{
  this_thread::sleep_for(time);
}

template void Sleep(chrono::nanoseconds);
template void Sleep(chrono::milliseconds);
template void Sleep(chrono::seconds);
template void Sleep(chrono::minutes);
template void Sleep(chrono::hours);

void get_ws(w_size &col, w_size &row)
{
  struct winsize ws;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) != -1)
  {
    // printf("terminal_width  =%d\n", ws.ws_col);
    // printf("terminal_height =%d\n", ws.ws_row);
    col = ws.ws_col;
    row = ws.ws_row;
  }
  else
  {
    throw runtime_error("ioctl is not enabled");
  }
}

void display(bool game[game_h][game_w / 2])
{
  Clear();

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
    cout << endl;
    }
}

Block::Block(bool game[game_h][game_w / 2]) : pattern{}
{
  rep(i, game_h)
  {
    this->game[i] = game[i];
  }
  rep(i, 2)
  {
    this->pos[i] = d_pos[i];
  }

  random_device rnd;
  this->mt = mt19937(rnd());
  this->rand7 = uniform_int_distribution<>(0, 6);

  this->dir = 0;
  this->set_block(0);
  this->render();
}

int Block::get_rand()
{
  return this->rand7(this->mt);
}

void Block::set_pattern(const bool pattern[4][4][4])
{
  rep(i, 4)
  {
    rep(j, 4)
    {
      rep(k, 4) this->pattern[i][j][k] = pattern[i][j][k];
    }
  }
}

void Block::set_block(int type)
{
  int block_type = type == -1 ? this->get_rand() : type;
  switch (type)
  {
  case 0:
    this->set_pattern(BLOCK_T);
    break;

  default:
    throw runtime_error("invalid block type");
  }
}

void Block::render()
{
  rep(i, 4)
  {
    rep(j, 4)
    {
      game[this->pos[0] + i][this->pos[1] + j] = this->pattern[this->dir][i][j];
    }
  }
}
