#include<iostream>
#include<algorithm>

using namespace std;

int N;
int cnt=0;

/* 1�̸� �� ���� ���ִ� ��, -1�̸� �� �ִ� ��*/
int map[15][15];

/* (i,j)�� queen�� ������ �� (i+1) ~ (N-1)���� queen �̵� �ݰ濡 0or 1���� */
void push_delete(int i,int j,int val){
	/* �밢�� ���ʿ� val ���� */
	int x=i+1;
	int y=j-1;
	while(x<N && y>=0){
		if(val>0 && map[x][y]==-1) map[x][y]=val;
		if(val<0 && map[x][y]==-val) map[x][y]=-1;
		x++;
		y--;
	}
	/* �밢�� �����ʿ� val���� */
	x=i+1;
	y=j+1;
	while(x<N && y<N){
		if(val>0 && map[x][y]==-1) map[x][y]=val;
		if(val<0 && map[x][y]==-val) map[x][y]=-1;
		x++;
		y++;
	}
	/* �Ʒ� ���� �� val ���� */
	x=i+1;
	y=j;
	while(x<N){
		if(val>0 && map[x][y]==-1) map[x][y]=val;
		if(val<0 && map[x][y]==-val) map[x][y]=-1;
		x++;
	}
}
/*i�࿡ queen�� �־*/
void dfs(int i){
	if(i==N) {
		cnt++;
		return;
	}
	for(int j=0;j<N;j++){
		if(map[i][j]==-1){
			/* (i,j)�� ���� ���� ���ִ� ������ 0���� */
			push_delete(i,j,i+1);
			dfs(i+1);
			/* �ٽ� ������ */
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