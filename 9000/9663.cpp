#include<iostream>
#include<algorithm>

using namespace std;

int N;
int cnt=0;

/* 1이면 퀸 넣을 수있는 곳, -1이면 못 넣는 곳*/
int map[15][15];

/* (i,j)에 queen이 놓였을 때 (i+1) ~ (N-1)행의 queen 이동 반경에 0or 1저장 */
void push_delete(int i,int j,int val){
	/* 대각선 왼쪽에 val 저장 */
	int x=i+1;
	int y=j-1;
	while(x<N && y>=0){
		if(val>0 && map[x][y]==-1) map[x][y]=val;
		if(val<0 && map[x][y]==-val) map[x][y]=-1;
		x++;
		y--;
	}
	/* 대각선 오른쪽에 val저장 */
	x=i+1;
	y=j+1;
	while(x<N && y<N){
		if(val>0 && map[x][y]==-1) map[x][y]=val;
		if(val<0 && map[x][y]==-val) map[x][y]=-1;
		x++;
		y++;
	}
	/* 아래 열에 쭉 val 저장 */
	x=i+1;
	y=j;
	while(x<N){
		if(val>0 && map[x][y]==-1) map[x][y]=val;
		if(val<0 && map[x][y]==-val) map[x][y]=-1;
		x++;
	}
}
/*i행에 queen을 넣어봄*/
void dfs(int i){
	if(i==N) {
		cnt++;
		return;
	}
	for(int j=0;j<N;j++){
		if(map[i][j]==-1){
			/* (i,j)에 퀸을 넣음 못넣는 공간에 0저장 */
			push_delete(i,j,i+1);
			dfs(i+1);
			/* 다시 돌려줌 */
			push_delete(i,j,-(i+1));
		}
		
	}
	return;
}

int main(){
	cin>>N;
	fill(&map[0][0],&map[0][0]+225,-1);
	
	dfs(0);
	cout<<cnt;
	return 0;
}