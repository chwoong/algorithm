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

int n,m;
int cnt=0;
map<deque<int>,int> v;
deque<int> ret[1000];
int adj[1001][1001];
int indegree[1001];
int outdegree[1001];
vector<int> circuit;
void make_edge(deque<int>& d){
	int i,o;
	int a=d[0];
	d.pop_front();
	if(v.count(d)){
		i=v[d];
	}else{
		ret[cnt]=d;
		v[d]=cnt++;
		i=v[d];
	}
	
	d.push_front(a);
	d.pop_back();
	if(v.count(d)){
		o=v[d];
	}else{
		ret[cnt]=d;
		v[d]=cnt++;
		o=v[d];
	}
	adj[o][i]++;
	indegree[i]++;
	outdegree[o]++;
}

void geteuler(int here){
	for(int i=0;i<cnt;i++){
		while(adj[here][i]>0){
			adj[here][i]--;
			geteuler(i);
		}
	}
	circuit.push_back(here);
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n-m+1;i++){
		deque<int> d;
		for(int j=0;j<m;j++){
			int x;
			scanf("%d",&x);
			d.push_back(x);
		}
		make_edge(d);
	}
	int s,e;
	for(int i=0;i<cnt;i++){
		//시작점
		if(indegree[i]==outdegree[i]-1) s=i;
		//끝점
		if(indegree[i]==outdegree[i]+1) e=i;
	}
	geteuler(s);
	reverse(circuit.begin(),circuit.end());
	for(int i=0;i<n-m+1;i++){
		printf("%d ",ret[circuit[i]][0]);
	}
	for(int i=0;i<m-1;i++){
		printf("%d ",ret[circuit[n-m+1]][i]);
	}
	return 0;
}