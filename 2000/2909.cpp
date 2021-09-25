#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<cmath>
using namespace std;
 
int c,k;

int main(){
	cin>>c>>k;
	int bill=1;
	while(k--)
		bill*=10;
	double n=bill*(c/bill);
	double m=n+bill;
	if((n+m)/2>c) cout<<(int)n;
	else cout<<(int)m;
	return 0;
}