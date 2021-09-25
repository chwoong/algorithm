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

typedef pair<int,int> P;
int n;
int d;
vector<P> v; 
vector<P> order;
int ans=0;
int ret=0;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int l,h;
		scanf("%d %d",&l,&h);
		if(l>h) swap(l,h);
		v.push_back(P(l,h));
	}
	cin>>d;
	for(int i=0;i<n;i++){
		if(v[i].second-v[i].first>d){
			continue;
		}else{
			order.push_back(P(v[i].second-d,1));
			order.push_back(P(v[i].first+1,-1));
		}
	}
	sort(order.begin(),order.end());
	for(auto& curr:order){
		if(curr.second==-1){
			ret--;
		}else{
			ret++;
			ans=max(ans,ret);
		}
	}
	cout<<ans;
	return 0;
}