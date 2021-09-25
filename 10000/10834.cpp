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
using namespace std;

int ans=1;
int d=1;
int M;
int main(){
	cin>>M;
	for(int i=0;i<M;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		ans/=a;
		ans*=b;
		if(c) d*=-1;
	}
	if(d==1) cout<<0<<" "<<ans;
	else cout<<1<<" "<<ans;
}