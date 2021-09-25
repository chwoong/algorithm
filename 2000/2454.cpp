/*
 *  author: chw0501
 *	reference: https://github.com/kks227/BOJ/blob/master/2400/2454.cpp
 *  created: 16.04.2020 10:50:38(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,k;
vector<int> adj[300001];
/*(curr과 연결되어있는 경로에서 아직 더 연결할 수 있는 정점의 개수,
curr부터 시작하는 트리에서 얻을 수 있는 최대 경로 개수) 반환*/
P dfs(int curr,int prev){
	int path=0;
	//두 개의 값을 저장할 것인데
	//curr의 자식들 중에 그 자식을 포함한 경로에서 아직 더 연결할 수 있는 정점의 개수
	//그런 것중에 가장 큰 값 2개(a>=b)
	int a=0;
	int b=0;
	for(int next:adj[curr]){
		if(next!=prev){
			P x=dfs(next,curr);
			if(a<x.first){
				b=a;
				a=x.first;
			}else if(b<x.first) b=x.first;
			path+=x.second;
		}
	}
	//(k+1-a)+(k+1-b)+1<=k+1  : a+b>k+1  이떄는 curr을 포함하고 a,b를 리턴한 두 자식까지 꺽여있는 경로를 선택
	//그러면 path개수에서 1개를 이득본다
	//이 경우에는 path개수에서 하나를 이득봤으므로 바로 밑의 두번째 케이스처럼 만드는 것도 가능하다.(따라서 최우선적으로 이경우를 선택)
	if(a+b>k+1) return P(0,path-1);
	//그게 아니면 아직 공간이 남는 것 중에 가장 많이 남는 것을 선택
	if(a) return P(a-1,path);
	//그것도 아니면 curr을 따로 하나의 경로로 떼고 나머지도 알아서 분할됨
	return P(k,path+1); 
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout<<dfs(1,0).second;
	return 0;
}