#include<bits/stdc++.h>
using namespace std;
class Queue {
public:
int sz=0;
    vector<int>v;
    Queue() {
      
    }  
   
    bool isEmpty() {
       if(sz==0) return true;
       else return false;
    }

    void push(int data) {
        sz++;
       v.push_back(data);
    }

    int pop() {
      //  if(v.empty()) return;
        sz--;
       v.pop_back();
    }

    int front() {
        if(sz==0) return -1;
      else return v.front();
    }
};
int main()
{
    Queue q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        q.push(value);
    }
    while(!q.isEmpty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}