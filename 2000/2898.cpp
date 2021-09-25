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
set<vector<P> > ans;

int w,l,n;
int u[1001];
int d[1001];

int main(){
	cin>>w>>l>>n;
	for(int i=0;i<n;i++){
		for(int i=0;i<l;i++)
			scanf("%d",u+i);
		for(int i=0;i<l;i++)
			scanf("%d",d+i);
		vector<P> k;
		int s=0;
		bool tmp=false;
		for(int i=0;i<l;i++){
			k.push_back(P(s,w-u[i]-d[i]));
			s=(s-u[i]+u[i+1]);
		}
		if(ans.count(k)!=0) tmp=true;
		s=0;
		k.clear();
		for(int i=l-1;i>=0;i--){
			k.push_back(P(s,w-u[i]-d[i]));
			if(i!=0) s=(s-u[i]+u[i-1]);
		}
		if(ans.count(k)!=0) tmp=true;
		s=0;
		k.clear();
		for(int i=0;i<l;i++){
			k.push_back(P(s,w-u[i]-d[i]));
			s=(s-d[i]+d[i+1]);
		}
		if(ans.count(k)!=0) tmp=true;
		s=0;
		k.clear();
		for(int i=l-1;i>=0;i--){
			k.push_back(P(s,w-u[i]-d[i]));
			if(i!=0) s=(s-d[i]+d[i-1]);
		}
		if(ans.count(k)!=0) tmp=true;
		if(tmp) continue;
		else ans.insert(k);
	}
	printf("%d",(int)ans.size());
	return 0;
}