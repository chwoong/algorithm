/*
 *  author: chw0501
 *  reference: https://jason9319.tistory.com/58
 *  created: 22.12.2020 11:40:29(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

int seg[400000];
int cnt[400000];
struct S{
	int x, y1, y2, se;
	bool operator<(S& tmp)const{
		return x < tmp.x;
	}
};

void update(int l, int r, int val, int node, int nodel, int noder){
	if(l > noder || r < nodel){
		return;
	}else if(l <= nodel && noder <= r){
		cnt[node] += val;
	}else{
		int mid = (nodel + noder) / 2;
		update(l, r, val, node * 2, nodel, mid);
		update(l, r, val, node * 2 + 1, mid + 1, noder);
	}
	if(cnt[node]) seg[node] = noder - nodel + 1;
	else{
		if(nodel == noder) seg[node] = 0;
		else seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
}

vector<S> v;

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
		v.push_back((S){x1, y1, y2 - 1, -1});
		v.push_back((S){x2, y1, y2 - 1, 1});
	}
	sort(v.begin(), v.end());
	int st = v[0].x;
	int len = 0;
	int ans = 0;
	for(int i = 0; i < 2 * n; i++){
		len = seg[1];
		ans += len * (v[i].x - st);
		st = v[i].x;
		update(v[i].y1, v[i].y2, -v[i].se, 1, 0, 30000);
	}
	printf("%d",ans);
	return 0;
}