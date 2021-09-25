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

int n,k,b;
bool breaked[100001];
int main(){
	cin>>n>>k>>b;
	for(int i=0;i<b;i++){
		int x;
		scanf("%d",&x);
		breaked[x]=true;
	}
	//고장난 것의 개수
	int ret=0;
	for(int i=1;i<=k;i++){
		if(breaked[i]==1) ret++;
	}
	int ans=ret;
	for(int j=k+1;j<=n;j++){
		if(breaked[j]==1) ret++;
		if(breaked[j-k]==1) ret--;
		ans=min(ret,ans);
	}
	cout<<ans;
	return 0;
}