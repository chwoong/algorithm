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
//»ö±òº°
vector<int> v[100001];
long long ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		sort(v[i].begin(),v[i].end());
	}
	for(int i=1;i<=n;i++){
		int len=v[i].size();
		if(len<=1) continue;
		for(int j=0;j<len;j++){
			if(j==0){
				ans+=(v[i][1]-v[i][0]);
			}else if(j==len-1){
				ans+=(v[i][len-1]-v[i][len-2]);	
			}else{
				ans+=min(v[i][j]-v[i][j-1],v[i][j+1]-v[i][j]);
			}
		}
	}
	cout<<ans;
	return 0;
}