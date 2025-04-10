#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    int arr[n][n];
    memset(arr, 0, sizeof(arr));
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;        
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int node1, node2;
        cin>>node1>>node2;
        if(arr[node1][node2]==1)
        cout<<"YES";
        else if(node1==node2)
        cout<<"YES";        
        else cout<<"NO";
        cout<<endl;
    }    
    return 0;
}