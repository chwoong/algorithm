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

long long n,k;

int main(){
	cin>>n>>k;
	long long ans=2019201997-(long long)84*(k-1)-(long long)48*n;
	cout<<ans;
	return 0;
}