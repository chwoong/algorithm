#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
using namespace std;

struct vector2{
	long long x,y;
	vector2(long long x_,long long y_):x(x_),y(y_){}
	double cross(vector2 & rhs){
		return x*rhs.y-y*rhs.x;
	}
};

vector<vector2> p;

int main(){
	int n;
	cin>>n;
	double ans=0;
	for(int i=0;i<n;i++){
		long long a,b;
		scanf("%lld %lld",&a,&b);
		p.push_back(vector2(a,b));
	}
	for(int i=0;i<n;i++){
		ans+=p[i].cross(p[(i+1)%n]);
	}
	printf("%.1f",ans>0?ans/2:-ans/2);
}