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

long long MAX=1000001;

int n,k;
vector<long long>v;
long long res[1001];

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int id;
		long long a,b,c;
		scanf("%d %lld %lld %lld",&id,&a,&b,&c);
		res[id]=MAX*MAX*a+MAX*b+c;
		v.push_back(res[i]);
	}
	sort(v.begin(),v.end());
	cout<<n+1-(upper_bound(v.begin(),v.end(),res[k])-v.begin());
	return 0;
}