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
int n,d;
int a[200000];
int b[200000];
int ans[200000];
set<P> x;
set<P> y;
queue<int> q;
int main(){
	cin>>n>>d;
	for(int i=0;i<2*n;i++){
		scanf("%d %d",a+i,b+i);
	}
	memset(ans,-1,sizeof(ans));
	for(int i=0;i<2*n;i++){
		if(a[i]==0 && i>=n){
			ans[i]=1;
			q.push(i);
		}else if(i>=n){
			y.insert(P(a[i],i));
		}
		if(b[i]==0 && i<n){
			ans[i]=1;
			q.push(i);
		}else if(i<n){
			x.insert(P(b[i],i));
		}
	}
	
	int len=2;
	while(!q.empty()){
		int l=q.size();
		for(int i=0;i<l;i++){
			int h=q.front();
		q.pop();
		if(h<n){
			while(1){
				set<P>:: iterator it=y.lower_bound(P(a[h]-d,-1));
				if(it==y.end() || a[h]<(*it).first) break;
				ans[(*it).second]=len;
				q.push((*it).second);
				y.erase(P((*it).first,(*it).second));
			}
		}else{
			while(1){
				set<P>:: iterator it=x.lower_bound(P(b[h]-d,-1));
				if(it==x.end() || b[h]<(*it).first) break;
				ans[(*it).second]=len;
				q.push((*it).second);
				x.erase(P((*it).first,(*it).second));	
			}
		}
		}
		len++;
	}
	for(int i=0;i<n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}