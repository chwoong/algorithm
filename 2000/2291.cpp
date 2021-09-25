#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
int n,m,k;

long long p[221][11]={0,};

void precalc(){
	p[0][0]=1;
	for(int i=1;i<=n;i++)
		p[i][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=m;j++){
			p[j][i]=p[j-1][i-1]+p[j-i][i];
		}
	}
}
void solve(int ch,int div,int sum,int order,vector<int>& path){
	if(div==1) {path.push_back(sum); return;}
	int a=0;
	for(int i=1;i<=ch;i++){
		a+=p[sum-i-(i-1)*(div-1)][div-1];
	}
	for(int i=ch;i<=sum/div;i++){
		if(a>=order) {path.push_back(i); solve(i,div-1,sum-i,order-(a-p[sum-i][div-1]),path);break;}
		a+=p[sum-(i+1)-i*(div-1)][div-1];
	}
}

int main(){
	cin>>n>>m>>k;
	precalc();
	vector<int> path;
	solve(1,n,m,k,path);
	for(int ele:path)
		cout<<ele<<" ";
	return 0;
}