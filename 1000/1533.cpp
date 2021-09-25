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

#define MOD 1000003
int n,s,e,t;

struct matrix{
	int res[51][51];
	matrix(){
		for(int i=0;i<51;i++){
			for(int j=0;j<51;j++){
				res[i][j]=0;
			}
		}
	}
	matrix operator*(const matrix& tmp){
		matrix x;
		for(int i=0;i<51;i++){
			for(int j=0;j<51;j++){
				for(int k=0;k<51;k++){
					x.res[i][j]=(x.res[i][j]+1ll*res[i][k]*tmp.res[k][j])%MOD;
				}
			}
		}
		return x;
	}
};

matrix m;

matrix solve(int num){
	if(num==1) return m;
	matrix a=solve(num/2);
	a=a*a;
	if(num%2==1) return a*m;
	else return a;
}

int main(){
	cin>>n>>s>>e>>t;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		for(int j=1;j<=n;j++){
			int x=s[j-1]-'0';
			if(x==0) continue;
			m.res[5*i][5*j-(x-1)]=1;
			for(int k=1;k<x;k++){
				m.res[5*j-k][5*j-(k-1)]=1;	
			}
		}
	}
	matrix ans=solve(t);
	cout<<ans.res[5*s][5*e];
	return 0;
}