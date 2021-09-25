/*
 *  author: chw0501
 *  created: 15.04.2020 07:54:28(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,m;
vector<int> fr[10001];
vector<int> en[10001];
vector<int> res;
vector<int> a;
int team[10001];
int num[2];
int ans=0;

void dfs(int here,int col){
	num[col]++;
	team[here]=col;
	for(int next:fr[here]){
		if(team[next]==-1){
			dfs(next,col);
		}else if(team[next]==!col){
			ans=-1;
		}
	}
	for(int next:en[here]){
		if(team[next]==-1){
			dfs(next,!col);
		}else if(team[next]==col){
			ans=-1;
		}
	}
}


int main(){
	for(int t=0;t<5;t++){
		cin>>n>>m;
		for(int i=0;i<10001;i++){
			fr[i].clear();
			en[i].clear();
		}
		memset(team,-1,sizeof(team));
		for(int i=0;i<m;i++){
			int x,u,v;
			scanf("%d %d %d",&x,&u,&v);
			if(x<0){
				en[u].push_back(v);
				en[v].push_back(u);
			}else{
				fr[u].push_back(v);
				fr[v].push_back(u);
			}
		}
		ans=0;
		res.clear();
		for(int i=1;i<=n;i++){
			if(team[i]==-1){
				num[0]=num[1]=0;
				dfs(i,0);
				res.push_back(abs(num[0]-num[1]));
			}
		}
		if(ans==-1) {puts("-1"); continue;}
		a.clear();
		a.push_back(res[0]);
		int x=res.size();
		for(int i=1;i<x;i++){
			int len=a.size();
			vector<int> b;
			b.clear();
			for(int j=0;j<len;j++){
				b.push_back(abs(a[j]+res[i]));
				b.push_back(abs(a[j]-res[i]));
			}
			sort(b.begin(),b.end());
			b.erase(unique(b.begin(),b.end()),b.end());
			a.swap(b);
		}
		printf("%d\n",a[0]);
		
	}
	return 0;
}