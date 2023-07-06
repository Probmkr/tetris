#include <iostream>
#include <thread>
#include <chrono>
#include <sys/ioctl.h>
#include <unistd.h>
#include "util.h"

using namespace std;

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
