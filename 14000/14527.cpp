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

typedef pair<int,int> P;
vector<P> v;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v.push_back(P(y,x));
	}
	sort(v.begin(),v.end());
	int i=0;
	int j=n-1;
	int a=0;
	while(i<=j){
		int m=min(v[i].second,v[j].second);
		a=max(a,v[i].first+v[j].first);
		if(i!=j){
			v[i].second-=m;
			v[j].second-=m;
		}else{
			v[i].second-=m;
		}
		if(v[i].second==0) i++;
		if(v[j].second==0) j--;
	}
	cout<<a;
	return 0;
}