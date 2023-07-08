#include <iostream>

using namespace std;

int main()
{
  int a[3][4] = {};
  int *p[3];
  for (int i = 0; i < 3; i++) {
    p[i] = a[i];
    // cout << a[i] << endl;
  }
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cout << p[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
