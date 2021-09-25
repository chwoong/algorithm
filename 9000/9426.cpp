/*
 *  author: chw0501
 *  reference: https://jason9319.tistory.com/48
 *  created: 26.12.2020 13:20:14(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 


int n, k;
int num[250000];
int seg[1010000];

void update(int pos, int val, int node, int nodel, int noder){
	if(pos < nodel || pos > noder) return;
	else if(pos == nodel && pos == noder) seg[node] += val;
	else{
		seg[node] += val;
		int mid = (nodel + noder) / 2;
		update(pos, val, node * 2, nodel, mid);
		update(pos, val, node * 2 + 1, mid + 1, noder);
	}
}

ll query(int val, int node, int nodel, int noder){
	int mid = (nodel + noder) / 2;
	if(nodel == noder) return nodel;
	if(seg[node * 2] >= val) return query(val, node * 2, nodel, mid);
	return query(val - seg[node * 2], node * 2 + 1, mid + 1, noder);
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", num + i);
	}
	for(int i = 0; i < k - 1; i++){
		update(num[i], 1, 1, 0, 65535);
	}
	ll ans = 0;
	for(int i = k - 1; i < n; i++){
		update(num[i], 1, 1, 0, 65535);
		ans += query((k + 1) / 2, 1, 0, 65535);
		update(num[i - k + 1], -1, 1, 0, 65535);
	}
	printf("%lld", ans);
	return 0;
}