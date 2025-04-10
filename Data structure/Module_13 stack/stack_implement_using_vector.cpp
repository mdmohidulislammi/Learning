#include<bits/stdc++.h>
using namespace std;
class myStack
{
    public:
          vector<int>vec;
          void push(int value)
          {
            vec.push_back(value);
          }
          void pop()
          {
            vec.pop_back();
          }
          int top()
          {
           return vec.back();
          }
          int size()
          {
            vec.size();
          }
          bool empty()
          {
            if(vec.size()==0) return true;
            else return false;
          }
};
int main()
{
    myStack st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        st.push(val);
    }
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}