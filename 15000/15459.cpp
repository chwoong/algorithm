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

int n;
long long m;
long long f[100000];
long long s[100000];
multiset<long long>ms;
int main(){
	cin>>n;
	cin>>m;
	for(int i=0;i<n;i++){
		scanf("%lld %lld",f+i,s+i);
	}
	int st=0;
	int en=0;
	long long sum=0;
	long long ans=1000000000;
	//[st~en)까지의 합에 대해 구하자.
	while(1){
		if(sum>=m){
			ans=min(ans,*ms.rbegin());
			ms.erase(ms.find(s[st]));
			sum-=f[st];
			st++;
		}else if(en==n) break;
		else{
			sum+=f[en];
			ms.insert(s[en]);
			en++;
		}
	}
	cout<<ans;
	return 0;
}