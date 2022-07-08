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

int N,P;
int cost[16][16];
/* dp[here]: ������ ���°� here�� �� �ʿ��� �ּ� �ݾ�*/
int dp[(1<<16)-1];
int start=0;

int solve(int curr,int leftinst){
	int &ret=dp[curr];
	if(ret!=-1) return ret;
	if(leftinst<=0) return ret=0;
	ret=1000;
	for(int i=0;i<N;i++){
		int next=curr | 1<<i;
		int val=50;
		/*���� ���´� next�̴�.*/
		if(next!=curr) {
			for(int j=0;j<N;j++){
				int who=curr | 1<<j;
				/* j�����ҷ� i�����Ҹ� ������ */
				if(who==curr) val=min(val,cost[j][i]);
			}
		}
		ret=min(ret,val+solve(next,leftinst-1));
	}
	return ret;
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>> cost[i][j];
	memset(dp,-1,sizeof(dp));
	string s;
	cin>>s;
	int numyes=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='Y') {start+=(1<<i); numyes++;}
	}
	cin>>P;
	if(start==0 && P>0) {cout<<-1; return 0;}
	cout<< solve(start,P-numyes);
	
	return 0;
}