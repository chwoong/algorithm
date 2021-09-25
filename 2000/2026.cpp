#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool adj[901][901]={false,};
vector<int>friends;

int K,N,F;
int cnt=0;

void dfs(int i){
	if(friends.size()==K){
		cnt=1;
		for(int m:friends)
			cout<<m<<endl;
	}	
	for(int l=i+1;l<=N&&cnt==0;l++){
		int tmp=friends.size();
		for(int j:friends){
			if(adj[j][l]==true) tmp--;
		}
		if(tmp==0){
			friends.push_back(l);
			dfs(l);
			friends.pop_back();
		}
	}
	return;
}

int main(){
	cin >> K >> N >> F;
	for(int i=0;i<F;i++){
		int j,k;
		cin >> j >> k;
		adj[j][k]=true;
		adj[k][j]=true;
	}
	for(int i=1;i<=N;i++){
		adj[0][i]=true;
	}
	dfs(0);
	if(cnt==0) cout<< "-1";
	return 0;
}