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
using namespace std;

int n;
int a[101];
int b[101];
int x[101];
int y[101];

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int p,q;
		scanf("%d %d",&p,&q);
		a[p]++;
		b[q]++;
		for(int j=1;j<=100;j++){
			x[j]=a[j];
			y[j]=b[j];
		}
		int u=1;
		int d=100;
		int ans=0;
		while(1){
			if(u==101 || d==0) break;
			int v1=x[u];
			int v2=y[d];
			if(v1>0 && v2>0){
				ans=max(ans,u+d);
				if(v1==v2) {u++; d--;}
				else if(v1>v2){
					x[u]-=v2;
					d--;
				}else{
					y[d]-=v1;
					u++;
				}
			}
			if(v1==0) u++;
			if(v2==0) d--;
		}
		printf("%d\n",ans);
	}
	return 0;
}