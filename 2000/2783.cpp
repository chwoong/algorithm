#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
#include<string>
#include<string.h>

using namespace std;

int x,y;
int n;
double m=100;
int main(){
	cin>>x>>y;
	m=min(m,double(x)/double(y));
	cin>>n;
	while(n--){
		int a,b;
		scanf("%d %d",&a,&b);
		m=min(m,double(a)/double(b));
	}
	cout.precision(10);
	cout<<1000.0*m;
	return 0;
}