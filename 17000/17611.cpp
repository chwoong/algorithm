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

typedef pair<int,int> P;
int n;
vector<P> point;
vector<P> hor;
vector<P> pal;
int ans;
int num;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		point.push_back(P(a,b));
	}
	for(int i=0;i<n;i++){
		int j=(i+1)%n;
		if(point[i].first==point[j].first){
			int a=point[i].second;
			int b=point[j].second;
			if(a>b) swap(a,b);
			hor.push_back(P(a,1));
			hor.push_back(P(b-1,2));
		}
		else{
			int a=point[i].first;
			int b=point[j].first;
			if(a>b) swap(a,b);
			pal.push_back(P(a,1));
			pal.push_back(P(b-1,2));
		}
	}
	sort(hor.begin(),hor.end());
	sort(pal.begin(),pal.end());
	for(P ele:hor){
		int tmp=(ele).second;
		if(tmp==1) num+=1;
		else num-=1;
		ans=max(ans,num);
	}
	num=0;
	for(P ele:pal){
		int tmp=(ele).second;
		if(tmp==1) num+=1;
		else num-=1;
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}