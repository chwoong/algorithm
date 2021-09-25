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
using namespace std;

int n;
int arr[1000];
int brr[1000];
int drr[1000];
int ans=0;

void solve(int i,int j){
	int s=i; int e=i;
	int m,k;
	while(s<=j){
		if(e==j+1){
			if(drr[s]<0) k=1;
				else k=0;
				for(int a=s;a<e;a++){
					if(k) drr[a]+=m;
					else drr[a]-=m;
				}
				solve(s,e-1);
				ans+=m;
				s=e;
			continue;
		}
		if(drr[s]==0) {s++; e=s; m=80; continue;}
		else{
			if(drr[s]*drr[e]>0){
				if(drr[s]<0) m=min(m,-drr[e]);
				else m=min(m,drr[e]);
				e++;
			}else{
				if(drr[s]<0) k=1;
				else k=0;
				for(int a=s;a<e;a++){
					if(k) drr[a]+=m;
					else drr[a]-=m;
				}
				solve(s,e-1);
				ans+=m;
				s=e;
			}
		}
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	for(int i=0;i<n;i++){
		scanf("%d",brr+i);
		drr[i]=brr[i]-arr[i];
	}
	solve(0,n-1);
	cout<<ans;
	return 0;
}