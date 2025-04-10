#include <bits/stdc++.h>
using namespace std;

class cmp {
public:
    // Define comparison logic: Returns true if 'a' should be after 'b'
    bool operator()(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
        // Compare based on the second integer value (marks)
        // This makes the priority queue a max-heap based on marks
        if(a.second.second<b.second.second)
        return true;
        else return false;
    }
};

int main() {
    int n;
    cin >> n;

    // Define the priority queue with custom comparator 'cmp'
    priority_queue<pair<string, pair<int, int>>, vector<pair<string, pair<int, int>>>, cmp> pq;

    // Input loop, corrected condition to 'i < n'
    for (int i = 0; i < n; i++) {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        pq.push({name, {roll, marks}});
    }

    // Print elements in the order defined by the comparator
    while (!pq.empty()) {
        // Accessing top element
       
        cout << pq.top().first << " " << pq.top().second.first << " " << pq.top().second.second << endl;
        pq.pop();
    }

    return 0;
}
