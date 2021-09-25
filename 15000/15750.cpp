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
using namespace std;

int n;
long long ans;
map<int,int> point;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		//이 값이 기본이다.
		ans+=abs(a-b);
		if(abs(a)>=abs(a-b)) continue;
		else{
			point[b]+=2;
			if((b>=a && a>=0)||(b<=a&&a<=0)){
				//이렇게해도 되네??
				point[2*b-2*a]--;
				point[2*a]--;
			}else if(a<=0 && b>=0){
				point[0]--;
				point[2*b]--;
			}else if(a>=0 && b<=0){
				point[0]--;
				point[2*b]--;
			}
		}
	}
	long long h,prev_slope(0), prev_y(-200000000);
	h=ans;
	for(map<int,int>::iterator it=point.begin();it!=point.end();it++){
		long long y=it->first;
		long long slope=it->second;
		long long val=prev_slope*(y-prev_y);
		prev_y=y;
		prev_slope+=slope;
		h=h+val;
		ans=min(ans,h);
	}
	cout<<ans;
	return 0;
}