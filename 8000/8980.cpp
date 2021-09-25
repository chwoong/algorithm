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
int n,c,m;
vector<P> v[2001];
int ans=0;
int ret[2001];

int main(){
	cin>>n>>c>>m;
	for(int i=0;i<m;i++){
		int u,w,b;
		scanf("%d %d %d",&u,&w,&b);
		v[w].push_back(P(u,b));
	}
	for(int i=2;i<=n;i++){
		sort(v[i].begin(),v[i].end());
	}
	for(int i=2;i<=n;i++){
		for(P& t:v[i]){
			int a=t.second;
			int st=t.first;
			int x=a;
			for(int j=st;j<i;j++){
				x=min(x,c-ret[j]);
			}
			for(int j=st;j<i;j++){
				ret[j]+=x;
			}
			ans+=x;
		}
	}
	cout<<ans;
	return 0;
}