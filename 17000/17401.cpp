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

#define MOD 1000000007
int t,n,d;
//num[i][j][k]: i->j의 걸린 시간이 k일 때 가짓수
long long num[20][20][101];
long long ret[20][20];

long long ans[20][20];

long long p[20][20];

void mul(int i){
	if(i==1){
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				ans[a][b]=num[a][b][t-1];
			}
		}
		return;
	}
	mul(i/2);
	long long res[20][20];
	memset(res,0,sizeof(res));
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			for(int c=0;c<n;c++){
				res[a][b]=(res[a][b]+(ans[a][c]*ans[c][b])%MOD)%MOD;
			}
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			ans[a][b]=res[a][b];
		}
	}
	long long res2[20][20];
	memset(res2,0,sizeof(res2));
	if(i%2==1){
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				for(int c=0;c<n;c++){
					res2[a][b]=(res2[a][b]+(ans[a][c]*num[c][b][t-1])%MOD)%MOD;
				}
			}
		}
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				res[a][b]=res2[a][b];
			}
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			ans[a][b]=res[a][b];
		}
	}
}

int main(){
	cin>>t>>n>>d;
	for(int i=0;i<t;i++){
		int m;
		cin>>m;
		memset(ret,0,sizeof(ret));
		for(int j=0;j<m;j++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			a--; b--;
			ret[a][b]=c;
		}
		for(int u=0;u<n;u++){
			for(int v=0;v<n;v++){
				for(int k=0;k<n;k++){
					if(i!=0) num[u][v][i]=(num[u][v][i]+(num[u][k][i-1]*ret[k][v])%MOD)%MOD;
				}
				if(i==0) num[u][v][i]=ret[u][v];
			}
		}
	}
	int x=d/t;
	int y=d%t;
	//num[t-1]을 x승 곱하고 y!=0이면 num[y-1]를 추가로 곱함
	if(x!=0) mul(x);
	else{
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%lld ",num[i][j][y-1]);
			}
			puts("");
		}
		return 0;
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			for(int c=0;c<n;c++){
				if(y!=0) p[a][b]=(p[a][b]+(ans[a][c]*num[c][b][y-1])%MOD)%MOD;
			}
		}
	}
	if(y==0){
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				p[a][b]=ans[a][b];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%lld ",p[i][j]);
		}
		puts("");
	}
	return 0;
}