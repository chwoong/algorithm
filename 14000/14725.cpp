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

int n,k;
vector<vector<string>> v;

void f(int i){
	for(int j=0;j<i;j++){
		printf("--");
	}
}

void solve(int l,int r,int k){
	//cout<<l<<' '<<r<<' '<<k<<endl;
	if(l==r){
		if(v[l].size()>k){
			f(k);
			cout<<v[l][k]<<'\n';
			solve(l,r,k+1);
			return;
		}else return;
	}else if(l>r){
		return;
	}
	string chk=v[l][k];
	int x=l;
	for(int i=l+1;i<=r;i++){
		if(v[i].size()>k){
			if(chk==v[i][k]){
				continue;
			}else if(chk!=v[i][k]){
				f(k);
				cout<<chk<<'\n';
				//cout<<x<<' '<<i-1<<endl;
				solve(x,i-1,k+1);
				x=i;
				chk=v[i][k];
			}
		}
	}
	f(k);
	cout<<v[x][k]<<'\n';
	solve(x,r,k+1);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		vector<string> v1;
		for(int j=0;j<k;j++){
			string s;
			cin>>s;
			v1.push_back(s);
		}
		v.push_back(v1);
	}
	sort(v.begin(),v.end());
	/*
	for(int i=0;i<(int)v.size();i++){
		for(string ele:v[i]){
			cout<<ele<<' ';
		}
	}
	*/
	solve(0,n-1,0);
	return 0;
}