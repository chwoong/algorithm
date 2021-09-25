/*
 *  author: chw0501
 *  reference: 
 *  created: 13.12.2020 10:47:48(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

int n, m;
int lazy[400000];
int seg[400000];

void propagate(int node, int nl, int nr){
	if(lazy[node] != 0){
		seg[node] = (nr - nl + 1) - seg[node];
		//리프노드가 아닌면
		if(nl != nr){
			lazy[node*2] ^= 1;
			lazy[node*2+1] ^= 1;
		}
		lazy[node] = 0;
	}
}

int update(int l, int r, int node, int nl, int nr){
	propagate(node, nl, nr);
	if(nl > r || nr < l) return seg[node];
	if(l <= nl && nr <= r){
		lazy[node] ^= 1;
		propagate(node, nl, nr);
		return seg[node];
	}
	int mid =(nl + nr) / 2;
	return seg[node] = update(l, r, node*2, nl, mid) + update(l, r, node*2+1, mid+1, nr);
}

int query(int l, int r, int node, int nl, int nr){
	propagate(node, nl, nr);
	if(nl > r || nr < l) return 0;
	else if(l <= nl && nr <= r) return seg[node];
	int mid = (nl + nr) / 2;
	return query(l, r, node*2, nl, mid) + query(l, r, node*2 + 1, mid + 1, nr);
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int o, s, t;
		scanf("%d %d %d", &o, &s, &t);
		if(o == 0){
			update(s, t, 1, 1, n);
		}else{
			printf("%d\n", query(s, t, 1, 1, n));
		}
	}
	return 0;
}