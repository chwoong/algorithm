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

int n,m;
vector<int> d[100];
int f=false;
//i번째 index까지 만든 수열이 s이다. 이 때 최종 결과를 반환
string solve(string s,int i){
	if(i==n-1){
		return s;
		f=true;
	}
	for(int k=1;k<=4;k++){
		bool ispos=true;
		for(int ele:d[i+1]){
			if(k==s[ele]-'0') {ispos=false; break;}
		}
		if(ispos){
			s+=('0'+k);
			return solve(s,i+1);	
		}
	}  
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a>b) swap(a,b);
		d[b-1].push_back(a-1);
	}
	cout<<solve("1",0);
	return 0;
}