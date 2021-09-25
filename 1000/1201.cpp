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

int n,m,k;
int main(){
	cin>>n>>m>>k;
	if(m+k-1<=n && n<=m*k){
		vector<int>v;
		for(int i=1;i<=n;i++)
			v.push_back(i);
		if(k!=1){
			int x=(n-m)/(k-1);
			int y=n-k*x;
			//k개짜리 x개 , y-(m-x-1)개짜리 1개, 1개짜리 m-x-1개
			for(int i=0;i<x;i++){
				reverse(v.begin()+k*i,v.begin()+k*(i+1));
			}
			reverse(v.begin()+k*x,v.begin()+k*x+y-(m-x-1));
		}
		for(int i=0;i<n;i++)
			printf("%d ",v[i]);
	}else{
		cout<<-1;
	}
	return 0;
}