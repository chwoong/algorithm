#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<cmath>
using namespace std;

typedef pair<int,int> P;

int N,M;
char map[50][50];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
P start;
bool visited[50][50][64]={false,};
int depth=0;
/* 갖고 있는 키 목록을 6bit로 저장하자*/
/* 키를 찾을 때마다 visited를 초기화하자 */

int bfs(){
	/* 위치와 키 목록 queue */
	queue<pair<P,int>> q;
	q.push(make_pair(start,0));
	visited[start.first][start.second][0]=true;
	while(!q.empty()){
		int len=q.size();
		for(int k=0;k<len;k++){
			pair<P,int> curr=q.front();
			q.pop();
			P here=curr.first;
			int key=curr.second;
			for(int i=0;i<4;i++){
				P next=make_pair(here.first+dx[i],here.second+dy[i]);
				int a=next.first;
				int b=next.second;
				/* 방문 조건 만족 시 */
				if(a>=0 && a<N && b>=0 && b<M && !visited[a][b][key] && map[a][b]!='#'){
					/* 빈칸 */
					if(map[a][b]=='.') {visited[a][b][key]=true; q.push(make_pair(next,key));}
					/* 출구 */
					else if(map[a][b]=='1') return depth+1;
					/* 열쇠 */
					else if(map[a][b]>='a' && map[a][b]<='f'){
						int newkey = key | (1<<(map[a][b]-'a'));
						visited[a][b][key]=true;
						q.push(make_pair(next,newkey));
					}
					/* 문을 열수 있으면 */
					else if( ((1<<(map[a][b]-'A')) | key) ==key ){	
						visited[a][b][key]=true;
						q.push(make_pair(next,key));
					}
				}
			}
		
		}//for
		depth++;
	}//while
	return -1;
}

int main(){
	cin>> N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
			if(map[i][j]=='0') {start=P(i,j); map[i][j]='.';}
		}
	}
	cout<<bfs();
	
	return 0;
}