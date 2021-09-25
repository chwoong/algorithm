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
int n,m;
vector<P> x;
vector<P> y;
int ans[100001];
int val;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a[3];
		int b[3];
		for(int j=0;j<3;j++){
			scanf("%d %d",a+j,b+j);
		}
		int m1=a[0];
		int m2=a[0];
		for(int j=1;j<3;j++) {m1=min(m1,a[j]); m2=max(m2,a[j]);}
		if((m1+1)!=m2){
			x.push_back(P(m1+1,0));
			x.push_back(P(m2,-1));
		}
		m1=b[0];
		m2=b[0];
		for(int j=1;j<3;j++) {m1=min(m1,b[j]); m2=max(m2,b[j]);}
		if((m1+1)!=m2){
			y.push_back(P(m1+1,0));
			y.push_back(P(m2,-1));
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		char s[20];
		scanf("%s",s);
		if(s[0]=='x'){
			scanf("%s",s);
			scanf("%d",&val);
			x.push_back(P(val,i));
		}
		else{
			scanf("%s",s);
			scanf("%d",&val);
			y.push_back(P(val,i));
		}
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	int ret=0;
	for(P& i:x){
		if(i.second==0){
			ret++;
		}else if(i.second<0){
			ret--;
		}else{
			ans[i.second]=ret;
		}
	}
	ret=0;
	for(P& i:y){
		if(i.second==0){
			ret++;
		}else if(i.second<0){
			ret--;
		}else{
			ans[i.second]=ret;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}