/*
 *  author: chw0501
 *  reference: 
 *  created: 28.12.2020 09:20:11(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

struct Point{
	int x, y;
	Point operator-(Point& tmp) const{
		return Point{x-tmp.x, y-tmp.y};
	}
	bool operator <(Point& tmp) const{
		return x != tmp.x ? x < tmp.x : y <tmp.y;
	}
};
struct Vec{
	Point p1,p2;
};

ll cross(Vec & v, Point & p){
	Point a = p - v.p1;
	Point b = v.p2 - v.p1;
	return a.x * b.y - a.y * b.x;
}
bool intersection(Vec v1, Vec v2){
	ll det1 = cross(v1, v2.p1) * cross(v1, v2.p2);
	ll det2 = cross(v2, v1.p1) * cross(v2, v1.p2);
	// 두 선분이 한직선에 있거나 끝점이 겹치는 경우
	if(det1 == 0 && det2 == 0){
		if(v1.p2 < v1.p1) swap(v1.p1, v1.p2);
		if(v2.p2 < v2.p1) swap(v2.p1, v2.p2);
		return !(v1.p2 < v2.p1 || v2.p2 < v1.p1);
	}
	return det1 <= 0 && det2 <= 0;
}

int n;
int p[3000];

int find(int i){
	if(p[i] < 0) return i;
	return p[i] = find(p[i]);
}

void merge(int i, int j){
	i = find(i);
	j = find(j);
	if(i == j) return;
	p[i] += p[j];
	p[j] = i;
}

int main(){
	scanf("%d", &n);
	vector<Vec> v;
	for(int i = 0; i < n; i++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		v.push_back((Vec){(Point){x1, y1}, (Point){x2, y2}});
	}
	for(int i = 0; i < n; i++){
		p[i] = -1;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(intersection(v[i], v[j])) merge(i, j);
		}
	}
	int ans = 0;
	int num = 0;
	for(int i = 0; i < n; i++){
		if(p[i] < 0){
			ans++;
			num = min(num, p[i]);
		}
	}
	printf("%d\n%d",ans,-num);
	
	return 0;
}