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

int main(){
	cin>>n>>k;
	if(n%k==0){
		if(n/k>k){
			puts("-1"); return 0;
		}else{
			for(int i=0;i<n/k;i++){
				for(int j=n-k*(i+1)+1;j<=n-k*i;j++){
					printf("%d ",j);
				}
			}
		}
	}else{
		if(n/k+1>k){
			puts("-1"); return 0;
		}else{
			for(int i=0;i<n/k;i++){
				for(int j=n-k*(i+1)+1;j<=n-k*i;j++){
					printf("%d ",j);
				}
			}
			for(int i=1;i<=n%k;i++){
				printf("%d ",i);
			}
		}
	}
	
	return 0;
}