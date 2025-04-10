#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
    bool operator()(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
    {
        if (a.second.second < b.second.second)
            return true;
        else if (a.second.second == b.second.second)
        {
            if (a.second.first > b.second.first)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};
int main()
{
    int n;
    cin >> n;
    priority_queue<pair<string, pair<int, int>>, vector<pair<string, pair<int, int>>>, cmp> pq;
    for (int i = 0; i < n; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        pq.push({name, {roll, marks}});
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int com;
        cin >> com;
        if (com == 0)
        {
            string new_s;
            int new_roll, new_marks;
            cin >> new_s >> new_roll >> new_marks;
            pq.push({new_s, {new_roll, new_marks}});
            if (!pq.empty())
                cout << pq.top().first << " " << pq.top().second.first << " " << pq.top().second.second;
            else
                cout << "Empty";
        }
        else if (com == 1)
        {
            if (!pq.empty())
                cout << pq.top().first << " " << pq.top().second.first << " " << pq.top().second.second;
            else
                cout << "Empty";
        }
        else
        {
            if (!pq.empty())
                pq.pop();
            if (!pq.empty())
                cout << pq.top().first << " " << pq.top().second.first << " " << pq.top().second.second;
            else
                cout << "Empty";
        }
        cout<<endl;
    }
    return 0;
}