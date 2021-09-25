/*
 *  author: chw0501
 *  reference: 
 *  created: 24.12.2020 08:57:17(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

int n;
string s;
int height[100][100];
int length[100][100];
int match[100];
//[i, j]사의 길의 거리 합 최소값
int solve(int i, int j){
	int& ret= length[i][j];
	if(ret != -1) return ret;
	if(i + 1 == j){
		height[i][j] = 1;
		return ret = 3;
	}
	int num = 0;
	int l = INF;
	int h = INF;
	//가장 밖에 테두리로 싸이는 경우
	if(s[i] != s[j]){
		int x = solve(i + 1, j - 1);
		l = min(l, x + 2 * (height[i + 1][j - 1] + 1) + j - i);
		h = min(h, height[i + 1][j - 1] + 1);
	}
	// 두 부분으로 나뉠 경우
	for(int k = i + 1; k < j; k++){
		//분기점이 될 수 있음
		if(s[k] != s[i] && num == 0){
			int x = solve(i, k);
			int y = solve(k + 1, j);
			l = min(l, x + y);
			int h_tmp = max(height[i][k], height[k + 1][j]);
			h = min(h, h_tmp);
		}
		num += (s[k] == '1' ? 1: -1);
	}
	height[i][j] = h;
	ret = l;
	return ret;
}

void trace(int i, int j){
	if(i >= j) return;
	if(i + 1 == j){
		match[i] = j;
		return;
	}
	if(s[i] != s[j]){
		int l = solve(i + 1, j -1);
		int h = height[i + 1][j - 1];
		if(solve(i, j) == l + 2 * (h + 1) + j - i){
			match[i] = j;
			trace(i + 1, j -1);
			return;
		}
	}
	int num = 0;
	for(int k = i + 1; k < j; k++){
		if(s[i] != s[k] && num == 0){
			int x = solve(i, k);
			int y = solve(k + 1, j);
			if(solve(i, j) == x + y){
				match[i] = k;
				trace(i + 1, k - 1);
				trace(k + 1, j);
				return;
			}
		}
		num += (s[k] == '1' ? 1: -1);
	}
}
int main(){
	scanf("%d", &n);
	cin >> s;
	memset(height, -1 ,sizeof(height));
	memset(length, -1, sizeof(length));
	memset(match, -1 , sizeof(match));
	printf("%d\n", solve(0, n - 1));
	trace(0, n - 1);
	for(int i = 0; i < n; i++){
		if(match[i] != -1) printf("%d %d\n", i + 1, match[i] + 1);
	}
	return 0;
}