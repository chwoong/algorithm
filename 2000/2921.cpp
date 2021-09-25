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

int n;
int main(){
	cin>>n;
	double x=n;
	cout<<n*(n+1)+(int)(x*x*x/2+x*x/2-x*(x-1)/4+x*x*(x-1)/2-(x-1)*x*(2*x-1)/4);
	return 0;
}