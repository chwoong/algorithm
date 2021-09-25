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
using namespace std;

typedef pair<int,int> P;
int n;
char m[50][50];
int val[50][50];
bool visited[50][50];
vector<int> v;
P s;
vector<P> e;
int dx[8]={1,0,-1,-1,-1, 0, 1,1};
int dy[8]={1,1, 1, 0,-1,-1,-1,0};
int ans=1000000;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		for(int j=0;j<n;j++){
			m[i][j]=x[j];
			if(m[i][j]=='K') e.push_back(P(i,j));
			else if(m[i][j]=='P') s=P(i,j);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&val[i][j]);
			v.push_back(val[i][j]);
		}
	}
	sort(v.begin(),v.end());
	int len=n*n;
	int l(0),h(0);
	while(l<len){
		bool tmp=true;
		memset(visited,false,sizeof(visited));
		int a=v[l];
		int b=v[h];
		queue<P> q;
		q.push(s);
		visited[s.first][s.second]=true;
		if(val[s.first][s.second]<a || val[s.first][s.second]>b) tmp=false;
		while(!q.empty()){
			P here=q.front();
			q.pop();
			for(int i=0;i<8;i++){
				int nx=here.first+dx[i];
				int ny=here.second+dy[i];
				if(nx>=0 && nx<n && ny>=0 && ny<n &&!visited[nx][ny] && val[nx][ny]>=a && val[nx][ny]<=b){
					visited[nx][ny]=true;
					q.push(P(nx,ny));
				}
			}
		}
		for(P ele:e){
			if(!visited[ele.first][ele.second]) tmp=false;
		}
		if(tmp){
			ans=min(ans,v[h]-v[l]);
			l++;
		}
		else if(h<len-1){
			h++;
		}else break;
	}
	cout<<ans<<endl;
	return 0;
}