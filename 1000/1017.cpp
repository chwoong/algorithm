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

int a[1010];
int b[1010];
vector<int> adj[1010];
bool visited[1010];
int prime[2000];


bool dfs(int i){
	if(visited[i]) return 0;
	visited[i]=true;
	for(int j:adj[i]){
		if(b[j]==-1 || dfs(b[j])){
			a[i]=j;
			b[j]=i;
			return 1;
		}
	}
	return 0;
}

int main(){
	int n;
	cin>>n;
	vector<int> v;
	vector<int> f;
	vector<int> s;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
		if(v[i]%2==v[0]%2) f.push_back(x);
		else s.push_back(x);
	}
	//2000미만까지의 소수 판별
	for(int i=2;i<2000;i++){
		if(prime[i]==0){
			prime[i]=i;
			for(int j=i*i;j<2000;j+=i){
				prime[j]=i;
			}
		}
	}
	//f - s 간의 매칭 확인
	//먼저 가능한 조합을 모두 확인
	for(int i:f){
		for(int j:s){
			if(prime[i+j]==(i+j)){
				adj[i].push_back(j);
			}
		}
	}
	vector<int> res;
	for(int j:s){
		//f의 첫번째 수와 j를 연결
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		if(prime[f[0]+j]==f[0]+j){
			a[f[0]]=j;
			b[j]=f[0];
			int ans=0;
			for(int i:f){
				memset(visited,0,sizeof(visited));
				visited[f[0]]=true;
				visited[j]=true;
				if(dfs(i)) {
					ans++; 
				}
			}
			if(ans==(n/2-1)) {res.push_back(j);}
		}
	}
	sort(res.begin(),res.end());
	if((int)res.size()==0){
		puts("-1");
	}else{
		for(int i:res){
			printf("%d ",i);
		}
	}
	return 0;
}