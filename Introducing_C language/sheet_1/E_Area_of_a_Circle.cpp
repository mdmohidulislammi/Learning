#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    cout << fixed <<setprecision(9);
    double n,pi=3.141592653;
    scanf("%lf",&n);
    double area=n*n*pi;
    printf("%.9lf",area);

}