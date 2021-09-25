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

typedef pair<long long,long long> P;
int t;
map<P,int> m;

int solve(long long l,long long r){
	if(m.count(P(l,r))) return m[P(l,r)];
	int ret=0;
	for(int i=1;i<=32;i++){
		long long x=((1ll)<<i)-1;
		long long y=((1ll)<<(i+1))-2;
		if(r>=x && l<=y){
			long long a=max(x,l);
			long long b=min(y,r);
			ret=max(ret,i+solve(a-x,b-x));
		}
	}
	m[P(l,r)]=ret;
	return ret;
}

int main(){
	cin>>t;
	m[P(0,0)]=0;
	m[P(1,1)]=1;
	m[P(1,2)]=2;
	m[P(2,2)]=2;
	while(t--){
		int a,b;
		scanf("%d %d",&a,&b);
		cout<<solve(a,b)<<endl;
	}
	return 0;
}