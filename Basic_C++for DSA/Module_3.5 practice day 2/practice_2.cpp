#include<bits/stdc++.h>
using namespace std;
class cricketer
{
    public:
    int jersey_no;
    char country_name[101];
};
int main()
{
    cricketer* dhoni  = new cricketer;
    cin>>dhoni->jersey_no>>dhoni->country_name;
    cricketer*kholi =new cricketer; 
    kholi->jersey_no= dhoni->jersey_no;
    strcpy(kholi->country_name,dhoni->country_name);
    delete dhoni;
    cout<<kholi->jersey_no<<" "<<kholi->country_name <<endl;
    cout<<dhoni->jersey_no<<" "<<dhoni->country_name <<endl;
    return 0;
}