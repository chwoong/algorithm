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
using namespace std;

typedef pair<int,int> P;
int n,q;
int arr[300001];
P query[300000];
vector<int> ans;
int p[300001];
bool notused[300001];
int find(int u){
	if(p[u]==u || p[u]==0) return p[u];
	return p[u]=find(p[u]);
}
void merge(int i,int j){
	i=find(i);
	j=find(j);
	if(i==j) p[i]=0;
	else p[i]=j;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
		p[i]=i;
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		query[i]=P(a,b);
		if(a==2) notused[b]=true;
	}
	for(int i=1;i<=n;i++){
		if(arr[i]>0&&!notused[i]) merge(i,arr[i]);
	}
	for(int i=q-1;i>=0;i--){
		int a=query[i].first;
		int b=query[i].second;
		if(a==1) ans.push_back(find(b));
		else merge(b,arr[b]);
	}
	reverse(ans.begin(),ans.end());
	for(int ele:ans){
		if(ele==0) puts("CIKLUS");
		else printf("%d\n",ele);
	}
	return 0;
}