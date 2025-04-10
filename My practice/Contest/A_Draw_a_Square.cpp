#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        long long int Diagonal1 = a + b, Diagonal2 = c + d;
        double edge1 = sqrt((a * a) + (c * c)), edge2 = sqrt((a * a) + (d * d)), edge3 = sqrt((b * b) + (c * c)), edge4 = sqrt((b * b) + (d * d));
        if (Diagonal1 == Diagonal2)
        {
            if (edge1 == edge2 && edge2 == edge3 && edge3 == edge4)
                cout
                    << "YES\n";
            else
                cout << "No\n";
        }
        else cout<<"No\n";
    }
    return 0;
}