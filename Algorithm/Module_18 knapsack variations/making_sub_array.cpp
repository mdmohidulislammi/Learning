#include <iostream>
#include <vector>
using namespace std;

// Function to generate all subsets of a given set
void generateSubsets(vector<int>& set) {
    int n = set.size();
    // Total number of subsets is 2^n
    int totalSubsets = 1 << n; // This is 2^n

    // Loop through each subset
    for (int i = 0; i < totalSubsets; ++i) {
        for (int j = 0; j < n; ++j) {
            // Check if the j-th element is in the subset
            if (i & (1 << j)) {
                cout  <<set[j]<<" ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> set;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        set.push_back(val);
    }
    generateSubsets(set);

    return 0;
}
