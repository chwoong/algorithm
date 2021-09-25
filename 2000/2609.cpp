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
#include<time.h>
using namespace std;

int gcd(int a,int b){
	if(a>b) swap(a,b);
	if(a==0) return b;
	else return gcd(a,b%a);
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	cout<<a*b/gcd(a,b);
	return 0;
}