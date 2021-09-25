#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

typedef pair<long long,int> P;
int n,k;
vector<P> jew;
multiset<int> c;

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int m,v;
		scanf("%d %d",&m,&v);
		jew.push_back(P(v,m));
	}
	sort(jew.begin(),jew.end());
	for(int i=0;i<k;i++){
		int x;
		scanf("%d",&x);
		c.insert(x);
	}
	long long ans=0;
	for(int i=n-1;i>=0;i--){
		multiset<int>::iterator it=c.lower_bound(jew[i].second);
		if(it==c.end()) continue;
		else{
			ans+=jew[i].first;
			c.erase(it);
			k--;
			if(k==0) break;
		}
	}
	cout<<ans;
	return 0;
}