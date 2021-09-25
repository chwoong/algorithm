#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
using namespace std;

int N;
vector<vector<int>> v;
int main(){
	cin>>N;
	v.resize(N+1);
	for(int i=0;i<N;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[b].push_back(a);
	}
	for(int i=1;i<N;i++){
		if(!v.empty()) sort(v[i].begin(),v[i].end());
	}
	int len=0;
	for(int i=1;i<=N;i++){
		if(!v[i].empty()){
			int s=v[i].size();
			for(int j=0;j<s;j++){
				if(j==0) len+=v[i][1]-v[i][0];
				else if(j==s-1) len+=v[i][s-1]-v[i][s-2];
				else len+=min(v[i][j]-v[i][j-1],v[i][j+1]-v[i][j]);
			}
		}
	}
	cout<<len;
}