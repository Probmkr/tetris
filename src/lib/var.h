#ifndef VAR_H
#define VAR_H
#include <string>


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
// short int game[game_h][game_w / 2] = {
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
//     {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {0, 0, 1, 1, 1, 1, 0, 1, 1, 1}};
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

#endif
