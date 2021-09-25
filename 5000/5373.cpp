/*
 *  author: chw0501
 *  reference: 
 *  created: 13.12.2020 02:34:13(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

int n, t;
//(U, D, F, B, L, R) = (0, 1, 2, 3, 4, 5) = (w, y, r, o, g, b)
int cube[6][3][3];
char col[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
map<char,int> dirt;
void init(){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				cube[i][j][k] = i;
			}
		}
	}
}

int temp[3][3];

void rotate(char pivot, int dir){
	int fix;
	if(dir == '+'){
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				temp[j][2-i] = cube[dirt[pivot]][i][j];
	}else{
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				temp[2-j][i] = cube[dirt[pivot]][i][j];
	}
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cube[dirt[pivot]][i][j] = temp[i][j];
	
	if(pivot == 'U' || pivot == 'D'){
		if(pivot == 'U') fix = 0;
		else {
			fix = 2;
			if(dir == '+') dir = '-';
			else dir = '+';
		}
		int tmp[3] = {cube[2][fix][0], cube[2][fix][1], cube[2][fix][2]};
		if(dir == '+'){
			for(int i = 0; i < 3; i++){
				cube[2][fix][i] = cube[5][fix][i];
				cube[5][fix][i] = cube[3][fix][i];
				cube[3][fix][i] = cube[4][fix][i];
				cube[4][fix][i] = tmp[i];
			}
		}else{
			for(int i = 0; i < 3; i++){
				cube[2][fix][i] = cube[4][fix][i];
				cube[4][fix][i] = cube[3][fix][i];
				cube[3][fix][i] = cube[5][fix][i];
				cube[5][fix][i] = tmp[i];
			}
		}
	}else if(pivot == 'F' || pivot == 'B'){
		if(pivot == 'F') fix = 2;
		else{
			fix = 0;
			if(dir == '+') dir = '-';
			else dir = '+';
		}
		int tmp[3] = {cube[0][fix][0], cube[0][fix][1], cube[0][fix][2]};
		if(dir == '+'){
			for(int i = 0; i < 3; i++){
				cube[0][fix][i] = cube[4][2-i][fix];
				cube[4][2-i][fix] = cube[1][2-fix][2-i];
				cube[1][2-fix][2-i] = cube[5][i][2-fix];
				cube[5][i][2-fix] = tmp[i];
			}
		}else{
			for(int i = 0; i < 3; i++){
				cube[0][fix][i] = cube[5][i][2-fix];
				cube[5][i][2-fix] = cube[1][2-fix][2-i];
				cube[1][2-fix][2-i] = cube[4][2-i][fix];
				cube[4][2-i][fix] = tmp[i];
			}
		}
	}else{
		if(pivot == 'L') fix = 0;
		else{
			fix = 2;
			if(dir == '+') dir = '-';
			else dir = '+';
		}
		int tmp[3] = {cube[0][0][fix], cube[0][1][fix], cube[0][2][fix]};
		if(dir == '+'){
			for(int i = 0; i < 3; i++){
				cube[0][i][fix] = cube[3][2-i][2-fix];
				cube[3][2-i][2-fix] = cube[1][i][fix];
				cube[1][i][fix] = cube[2][i][fix];
				cube[2][i][fix] = tmp[i];
			}
		}else{
			for(int i = 0; i < 3; i++){
				cube[0][i][fix] = cube[2][i][fix];
				cube[2][i][fix] = cube[1][i][fix];
				cube[1][i][fix] = cube[3][2-i][2-fix];
				cube[3][2-i][2-fix] = tmp[i];
			}
		}
	}
}


int main(){
	dirt['U'] = 0;
	dirt['D'] = 1;
	dirt['F'] = 2;
	dirt['B'] = 3;
	dirt['L'] = 4;
	dirt['R'] = 5;
	scanf("%d",&t);
	for(int i=0; i<t; i++){
		scanf("%d", &n);
		init();
		for(int p = 0; p < n; p++){
			char m[5];
			scanf("%s", m);
			rotate(m[0], m[1]);
		}
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				printf("%c", col[cube[0][j][k]]);
			}
			printf("\n");
		}
	}
	
	return 0;
}