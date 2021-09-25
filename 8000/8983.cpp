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

int m,n,l;
vector<int> sade;
int ans=0;

int main(){
	cin>>m>>n>>l;
	for(int i=0;i<m;i++){
		int x;
		scanf("%d",&x);
		sade.push_back(x);
	}
	sort(sade.begin(),sade.end());
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		//a와 가장 가까운 sade위치
		int x=lower_bound(sade.begin(),sade.end(),a)-sade.begin();
		int y=0;
		if(x!=0) y=x-1;
		if(x==m) x=y;
		int v=min(abs(sade[x]-a),abs(sade[y]-a));
		if(v+b<=l) ans++;
	}
	cout<<ans;
	return 0;
}