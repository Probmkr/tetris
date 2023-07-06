#ifndef CLEAR_H
#define CLEAR_H

using w_size = unsigned short;

void Clear(bool flush = true);

template <class T>
void Sleep(T);

void get_ws(w_size&, w_size&);

#endif
