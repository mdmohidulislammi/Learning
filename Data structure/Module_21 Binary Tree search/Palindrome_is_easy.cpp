#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool canMakePalindrome(const vector<vector<int>> &freq, int L, int R, int K)
{
    int odd_count = 0;

    for (int i = 0; i < 26; ++i)
    {
        int char_count = freq[i][R] - (L > 0 ? freq[i][L - 1] : 0);
        if (char_count % 2 != 0)
        {
            odd_count++;
        }
    }
    int min_changes = odd_count / 2;
    return min_changes <= K;
}

int main()
{
    int N, Q;
    string S;
    cin >> N >> S >> Q;
    vector<vector<int>> freq(26, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
    {
        if (i > 0)
        {
            for (int j = 0; j < 26; ++j)
            {
                freq[j][i] = freq[j][i - 1];
            }
        }
        freq[S[i] - 'a'][i]++;
    }
    while (Q--)
    {
        int L, R, K;
        cin >> L >> R >> K;
        L--;
        R--;
        if (canMakePalindrome(freq, L, R, K))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
