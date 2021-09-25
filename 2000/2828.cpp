#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;

int N,M,J;
queue<int>q;
int main(){
	cin>>N>>M>>J;
	for(int i=0;i<J;i++){
		int x;
		cin>>x;
		q.push(x);
	}
	int move=0;
	int s,e;
	s=1;
	e=s+M-1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(s<=x && x<=e) continue;
		else if(x<s){
			move+=(s-x); s=x; e=s+M-1;
		}else{
			move+=(x-e); e=x; s=e-(M-1);
		}
	}
	cout<<move;
	return 0;
}