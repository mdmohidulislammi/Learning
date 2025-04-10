#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
    bool operator()(pair<string, int> &a, pair<string, int> &b)
    {        
        if(a.first==b.first)
        {
            if(a.second<b.second)
            return true;
            else return false;
        }
        else if(a.first>b.first)
        return true;
        else 
        return false;
    }
};
int main()
{
    int n;
    cin >> n;
    map<string, int> m;
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
    for (int i = 0; i < n; i++)
    {
        string s;
        int val;
        cin >> s >> val;
        pq.push({s, val});
    }

    while (!pq.empty())
    {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}