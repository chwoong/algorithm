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


int n;
long long x[1000];
long long y[1000];

int p[1000];

int find(int i){
	if(p[i]<0) return i;
	return p[i]=find(p[i]);
}
void merge(int i,int j){
	i=find(i);
	j=find(j);
	if(i==j) return;
	p[i]+=p[j];
	p[j]=i;
}

struct S{
	//거리와 두 점 번호
	long long dist;
	int i,j;
	bool operator <(const S& tmp)const {
		return dist<tmp.dist;
	}
};
long long d(int i,int j){
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

vector<S> s;

int main(){
	cin>>n;
	memset(p,-1,sizeof(p));
	for(int i=0;i<n;i++){
		scanf("%lld %lld",x+i,y+i);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			s.push_back((S){d(i,j),i,j});
		}
	}
	sort(s.begin(),s.end());
	for(S here:s){
		merge(here.i,here.j);
		int x=find(here.i);
		if(-p[x]==n){
			cout<<here.dist;
			break;
		}
	}
}