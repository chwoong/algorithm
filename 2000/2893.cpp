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

struct tri{
	int x,y,r;
	tri(int x_,int y_,int r_):x(x_),y(y_),r(r_){}
	bool operator<(const tri & t) const{
		return x<t.x;
	}
};

int n;
vector<tri> v;
double ans;

tri solve(tri a,tri b){
	if(b<a) swap(a,b);
	//만약 a와 b의 교집합이 없다면 case
	if(b.x+b.y>=a.x+a.y+a.r) return tri(0,0,0);
	if(b.x>=a.x+a.r) return tri(0,0,0);
	if(b.y+b.r<=a.y) return tri(0,0,0);
	
	//그 외에는 교집합이 존재함
	int x=b.x;
	int y=max(b.y,a.y);
	int r=min(b.y+b.r-y,a.x+a.y+a.r-x-y);
	return tri(x,y,r);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		v.push_back((tri){a,b,c});
	}
	sort(v.begin(),v.end());
	int k=1<<n;
	while(--k){
		//k에 해당되는 삼각형 집합의 교집합 생각
		//k에 해당하는 1의 개수(with 포함배제)
		int num=0;
		vector<int> t;
		tri cross=(tri){0,0,10000000};
		for(int i=0;i<n;i++)
			if(k & (1<<i)){
				cross=solve(cross,v[i]);
				num++;
			}
		if(num%2==1) ans+=(1<<(num-1))*(double)cross.r*cross.r/2.0;
		else ans-=(1<<(num-1))*(double)cross.r*cross.r/2.0;
	}
	printf("%.1f",ans);
}