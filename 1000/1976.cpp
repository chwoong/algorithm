#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>
#include<cmath>

using namespace std;

int n,m;
int p[201];

int find(int i){
	if(p[i]==-1) return i;
	p[i]=find(p[i]);
	return p[i];
}

void merge(int a, int b){
	int f1=find(a);
	int f2=find(b);
	if(f1==f2) return;
	p[f2]=f1;
}

int main(){
	cin>>n>>m;
	memset(p,-1,sizeof(p));
	int x;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>x;
			if(x==1) merge(i,j); 
		}
	}
	cin >> x;
	int root=find(x);
	int tmp=1;
	for(int i=1;i<m;i++){
		cin>>x;
		if(root!=find(x)) {tmp=0; break;}
	}
	tmp ? cout<< "YES" : cout<<"NO";
	return 0;
}