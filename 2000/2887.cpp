#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

typedef pair<int,int> P;
P x[100000];
P y[100000];
P z[100000];

struct edge{
	int u,v;
	double w;	
}e[1000000];
bool operator<(edge a,edge b){return a.w<b.w;}

int p[100000];

int find(int i){
	if(p[i]==i) return i;
	return p[i]=find(p[i]);
}

void merge(int i,int j){
	i=find(i);
	j=find(j);
	if(i==j) return;
	p[i]=j;
}

int n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		p[i]=i;
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		x[i]=P(a,i);
		y[i]=P(b,i);
		z[i]=P(c,i);
	}
	sort(x,x+n);
	sort(y,y+n);
	sort(z,z+n);
	vector<pair<int,P> > v;
	for(int i=0;i<n-1;i++){
		P p,q;
		p=x[i];q=x[i+1];
		v.push_back(make_pair(abs(x[i].first-x[i+1].first),P(x[i].second,x[i+1].second)));
		p=y[i];q=y[i+1];
		v.push_back(make_pair(abs(y[i].first-y[i+1].first),P(y[i].second,y[i+1].second)));
		p=z[i];q=z[i+1];
		v.push_back(make_pair(abs(z[i].first-z[i+1].first),P(z[i].second,z[i+1].second)));
	}
	sort(v.begin(),v.end());
	long long ans=0;
	for(int i=0;i<3*(n-1);i++){
		P here=v[i].second;
		int a=here.first;
		int b=here.second;
		if(find(a)==find(b)) continue;
		merge(a,b);
		ans+=v[i].first;
	}
	cout<<ans;
	return 0;
}