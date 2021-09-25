#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<cmath>
#include<time.h>
using namespace std;


struct Point{
	//실제 위치
	long long x,y;
	//기준점에 대한 상대 위치
	long long p,q;
	bool operator<(const Point&tmp){
		// q/p < tmp.q/tmp.p 순서로 정렬할 것이다.(각도정렬)
		if(q*tmp.p != tmp.q*p) return q*tmp.p<tmp.q*p;
		if(y!=tmp.y) return y<tmp.y;
		return x<tmp.x;
	}
};

//a->b->c가 ccw인지 확인
long long ccw(const Point&a,const Point&b,const Point&c){ 
	return -(c.x-b.x)*(b.y-a.y)+(c.y-b.y)*(b.x-a.x);
}
vector<Point> v;
int n;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		Point a;
		a.x=x; a.y=y;
		a.p=0; a.q=0;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	for(int i=1;i<n;i++){
		v[i].p=v[i].x-v[0].x;
		v[i].q=v[i].y-v[0].y;
	}
	sort(v.begin()+1,v.end());
	stack<int> s;
	s.push(0);
	s.push(1);
	int next=2;
	while(next<n){
		while(s.size()>=2){
			int i1=s.top();
			s.pop();
			int i2=s.top();
			if(ccw(v[i2],v[i1],v[next])>0){
				s.push(i1);
				break;
			}
		}
		s.push(next++);
	}
	printf("%d",(int)s.size());
	return 0;
}