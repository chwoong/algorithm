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
using namespace std;

typedef pair<int,int> P;
int n,k,sx,sy;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int p[100000];
queue<P> q;
int m[2001][2001];
int visited[2001][2001];

int find(int i){
	if(p[i]<0) return i;
	else return p[i]=find(p[i]);
}
void merge(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b) return;
	p[b]+=p[a];
	p[a]=b;
}

int main(){
	cin>>n>>k;
	memset(p,-1,sizeof(p));
	memset(m,-1,sizeof(m));
	for(int i=0;i<k;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		m[a][b]=i;
		q.push(P(a,b));
		visited[a][b]=true;
		sx=a; sy=b;
	}
	int ans=0;
	while(!q.empty()){
		int len=q.size();
		for(int i=0;i<len;i++){
			P here=q.front();
			q.pop();
			int x=here.first;
			int y=here.second;
			visited[x][y]=2;
			for(int k=0;k<4;k++){
				int nx=x+dx[k];
				int ny=y+dy[k];
				if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
					//m[x][y]와 m[nx][ny]가 결합되어야 한다.
					if(visited[nx][ny]==2&&m[x][y]!=m[nx][ny] && m[nx][ny]!=-1){
						merge(m[x][y],m[nx][ny]);
					}
					if(!visited[nx][ny]){
						visited[nx][ny]=1;
						m[nx][ny]=m[x][y];
						q.push(P(nx,ny));
					}
				}
			}
		}
		int j=find(m[sx][sy]);
		if(p[j]==-k){
			printf("%d",ans);
			return 0;
		}
		ans++;
	}
	return 0;
}