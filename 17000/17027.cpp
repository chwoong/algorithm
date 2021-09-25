#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<set>
#include<stdlib.h>
#include<string>
#include<utility>
#include<stack>
using namespace std;

int n;
int g[100];
int a[100];
int b[100];
int ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %d %d",a+i,b+i,g+i);
	}
	for(int k=1;k<=3;k++){
		int tmp=0;
		int p=k;
		for(int i=0;i<n;i++){
			if(p==a[i]) p=b[i];
			else if(p==b[i]) p=a[i];
			if(g[i]==p) tmp++;
		}
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
}