/*
 *  author: chw0501
 *  reference: 
 *  created: 18.12.2020 03:43:37(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

int n, m;
int seg[2000000];
int lazy[2000000];

void propagate(int node, int nodel, int noder){
	if(lazy[node] != 0){
		if((noder - nodel + 1) % 2 ==1){
			seg[node] ^= lazy[node];
		}
		if(nodel != noder){
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

int update(int l, int r, int k, int node, int nodel,int noder){
	propagate(node, nodel, noder);
	if(l > noder || r < nodel) return seg[node];
	else if(l <= nodel && noder <= r){
		lazy[node] += k;
		propagate(node, nodel, noder);
		return seg[node];
	}
	int mid = (nodel + noder) / 2;
	return seg[node] = update(l, r, k, node * 2, nodel, mid) ^ update(l, r, k, node * 2 + 1, mid + 1, noder);
}

int query(int l, int r, int node, int nodel, int noder){
	propagate(node, nodel, noder);
	if(l > noder || r < nodel) return 0;
	else if(l <= nodel && noder <= r) return seg[node];
	int mid = (nodel + noder) / 2;
	return query(l, r, node * 2, nodel, mid) ^ query(l, r, node * 2 + 1, mid + 1, noder);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int tmp;
		scanf("%d", &tmp);
		update(i, i, tmp, 1, 0, n - 1);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int a, b, c, d;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 1){
			scanf("%d", &d);
			update(b, c, d, 1, 0, n - 1);
		}else{
			printf("%d\n", query(b, c, 1, 0, n - 1));
		}
	}
	return 0;
}