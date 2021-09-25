#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<set>
#include<stdlib.h>
#include<string>
#include<utility>
#include<stack>
using namespace std;

int n;
vector<string> v[100];

int com(int i,int j){
	int a=v[i].size();
	int b=v[j].size();
	int cnt=0;
	for(int x=0;x<a;x++){
		for(int y=0;y<b;y++){
			if(v[i][x]==v[j][y]) cnt++;
		}
	}
	return cnt;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>s;
			v[i].push_back(s);
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans=max(ans,com(i,j));
		}
	}
	cout<<ans+1;
	return 0;
}