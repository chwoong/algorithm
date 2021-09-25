/*
 *  author: chw0501
 *  reference: 
 *  created: 06.12.2020 06:30:17(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

int n, k;
int num[100001];
int fen[3][100001];	//0: 음수 1: 0 2: 양수

int judge(int i){
	if(i > 0) return 2;
	else if(i == 0) return 1;
	else return 0;
}

void update(int pos, int sign, int val){
	while(pos <= n){
		fen[sign][pos] += val;
		pos += (pos & -pos); 
	}
}
//sign에 해당하는 펜윅트리의 pos index의 값을 반환
int query(int pos, int sign){
	int ret = 0;
	while(pos > 0){
		ret += fen[sign][pos];
		pos -= (pos & -pos);
	}
	return ret;
}

int main(){
	while(scanf("%d %d", &n, &k) != EOF) {
		memset(fen, 0, sizeof(fen));
		for(int i = 1; i <= n; i++) {
			scanf("%d", num+i);
			update(i, judge(num[i]), 1);
		}
		for(int i = 1; i <= k; i++){
			char s[2];
			int a, b;
			scanf("%s",s);
			scanf("%d %d", &a, &b);
			if(s[0] == 'C'){
				update(a, judge(num[a]), -1);
				num[a] = b;
				update(a, judge(num[a]), 1);
			}else{
				int zero = query(b, 1) - query(a-1, 1);
				int minus = query(b, 0) - query(a-1, 0);
				if(zero) printf("0");
				else if(minus % 2 == 1) printf("-");
				else printf("+");
			}
		}
		printf("\n");
	}
	return 0;
}