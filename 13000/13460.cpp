/*
 *  author: chw0501
 *  reference: 
 *  created: 17.12.2020 09:13:29(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

int n, m;
int r, b, o;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[11][11];
int visited[100][100];

bool inboard(int p){
	return ((p / 10) >= 1) && ((p / 10) < n-1) && ((p % 10) >= 1) && ((p % 10) < m-1);
}


//dir방향으로 굴렸을 때 red, blue의 최종위치 반환
//(ex) (0,*)이면 red가 구멍에 빠졌다는 뜻
P simulate(int red, int blue, int dir){
	int rx = red / 10; int ry = red % 10;
	int bx = blue / 10; int by = blue % 10;
	int mx = dx[dir];
	int my = dy[dir];
	int mv = 10*mx + my;
	int tmp1 = 1; int tmp2 = 1;	// -1: 못움직임 0: 구멍에 빠짐 1: 움직임
	while(1){
		//red공
		if(tmp1 == 1 && inboard(red+mv) && (board[rx + mx][ry + my] == '#' || (rx + mx == bx && ry + my == by))){
			tmp1 = -1;
		}else if(tmp1 == 1 && inboard(red+mv) && board[rx + mx][ry + my] == 'O'){
			tmp1 = 0;
			rx = 0; ry = 0;
		}else if(inboard(red+mv)){
			tmp1 = 1;
			rx += mx; ry += my;
		}else{
			tmp1 = -1;
		}
		//blue공
		if(tmp2 == 1 && inboard(blue+mv) &&(board[bx + mx][by + my] == '#' || (bx + mx == rx && by + my == ry))){
			tmp2 = -1;
		}else if(tmp2 == 1 && inboard(blue+mv) && board[bx + mx][by + my] == 'O'){
			tmp2 = 0;
			bx = 0; by = 0;
		}else if(inboard(blue+mv)){
			tmp2 = 1;
			bx += mx; by += my;
		}else{
			tmp2 = -1;
		}
		red = rx * 10 + ry;
		blue = bx * 10 + by;
		if(tmp1 != 1 && tmp2 != 1) break;
		if(tmp1 == -1 && tmp2 != -1) tmp1 = 1;
		if(tmp1 != -1 && tmp2 == -1) tmp2 = 1;
	}
	return P(red, blue);
}


int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%s", board[i]);
		for(int j = 0; j < m; j++){
			if(board[i][j] == 'R') {r = 10*i + j;}
			else if(board[i][j] == 'B') {b = 10*i + j;}
			else if(board[i][j] == 'O') {o = 10*i + j;}
		}
	}
	visited[r][b] = 1;
	queue<P> q;
	q.push(P(r,b));
	int len = 0;
	while(len < 10){
		len++;
		int s = q.size();
		for(int i = 0; i < s; i++){
			P here = q.front();
			q.pop();
			for(int k = 0; k < 4; k++){
				P move = simulate(here.first, here.second,k);
				if(move.first == 0 && move.second !=0){
					printf("%d", len);
					return 0;
				}
				if(visited[move.first][move.second] == 0){
					visited[move.first][move.second] == 1;
					q.push(P(move.first, move.second));
				}
			}
		}
	}
	printf("-1");
	return 0;
}