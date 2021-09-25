#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
using namespace std;
typedef pair<int,int> P;

int c,r;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char map[1001][1001];
bool visited[1001][1001];
int depth;
P bfs(P curr){
	P ret;
	ret=curr;
	depth=-1;
	visited[curr.first][curr.second]=true;
	queue<P> q;
	q.push(curr);
	while(1){
		if(q.empty()) return ret;
		int len=q.size();
		while(len--){
			P here=q.front();
			q.pop();
			int hx=here.first;
			int hy=here.second;
			for(int i=0;i<4;i++){
				int nx=hx+dx[i];
				int ny=hy+dy[i];
				if(nx>=1 && nx<r && ny>=1 && ny<c && map[nx][ny]=='.' && !visited[nx][ny]){
					visited[nx][ny]=true;
					ret=P(nx,ny);
					q.push(ret);
				}
			}
		}
		depth++;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>c>>r;
		/*루트(아무 점) 찾아서 bfs*/
		P root;
		/*데이터 저장*/
		int u=1;
		for(int i=0;i<r;i++){
			char s[1001];
			scanf("%s",s);
			for(int j=0;j<c;j++){
				map[i][j]=s[j];
				if(u && map[i][j]=='.') {u=0; root=P(i,j);}
			}
		}
		if(u==1) {
			printf("Maximum rope length is 0.");
			continue;
		}
		/*root에서 bfs해서 마지막 점*/
		memset(visited,false,sizeof(visited));
		root=bfs(root);
		memset(visited,false,sizeof(visited));
		bfs(root);
		printf("Maximum rope length is %d.\n",depth);
	}
	return 0;
}