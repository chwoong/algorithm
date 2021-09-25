#include <iostream>
#include <string>
using namespace std;

long long a,c;

int multi(long long b){
    if(b==1) return a;
    long long x = multi(b/2)%c;
    if(b%2) return ((x*x)%c*a)%c;
    else return (x*x)%c;
}

int main()
{
    long long b;
    cin >> a >> b >> c;
    a %= c;
    cout << multi(b);
    
    return 0;
}