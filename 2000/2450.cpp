#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100000];

int solve(int i,int j,int k){
	int v1=0;
	int v2=0;
	int v3=0;
	for(int l=0;l<n;l++){
		if(arr[l]==i) v1++;
		else if(arr[l]==j) v2++;
		else v3++;
	}
	int ret=0;
	int v=0;
	for(int x=0;x<v1;x++){
		if(arr[x]!=i) ret++;
		if(arr[x]==j) v++;
	}
	int m=0;
	for(int x=v1;x<v1+v2;x++){
		if(arr[x]==i) m++;
		else if(arr[x]==k) ret++;
	}
	ret+=max(0,m-v);
	return ret;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	int ans=100000;
	for(int i=1;i<4;i++){
		for(int j=1;j<4;j++){
			for(int k=1;k<4;k++){
				if(i!=j && j!=k && k!=i){
					ans=min(ans,solve(i,j,k));
				}
			}
		}
	}
	cout<<ans;
	return 0;
}