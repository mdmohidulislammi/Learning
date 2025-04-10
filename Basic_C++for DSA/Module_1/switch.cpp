#include<iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    switch(x)
    {
        case 1:
        cout<< "one"<<endl;
        break;
        case 2:
        cout<<"two"<<endl;
        break;
        case 3:
        cout<<"three"<<endl;
        break;
        case 4:
        cout<<"four"<<endl;
        break;
        case 5:
        cout<<"five"<<endl;
        break;
        default:// eta kono condition na mille execute kore
        cout<<"Kichui mile nai"<<endl;

    }
    return 0;
}