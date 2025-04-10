#include <bits/stdc++.h>
using namespace std;
int main()
{
  int startLoop;
  cin >> startLoop;
  for (int p = 0; p < startLoop; p++)
  {
    int n;
    cin >> n;
    int st;
    for (int i = 1; i <= n; i++)
    {
      cout << "I love my self ." << endl;
      if (i == n)
        break;
      for (int j = 0; j <= i; j++)
      {
        st = j;
        cout << "  ";
      }
    }
    for (int i = 1; i <= n; i++)
    {
      for (int j = st; j > 0; j--)
        cout << "  ";
      cout << "I love my self ." << endl;
      st--;
    }
  }
  return 0;
}