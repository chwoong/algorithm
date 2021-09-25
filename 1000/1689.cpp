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

typedef pair<int,int> P;
int n;
vector<P> d;
int ans;
int num;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		d.push_back(P(a,1)); //Áõ°¡
		d.push_back(P(b-1,2)); //±è¼Ò
	}
	sort(d.begin(),d.end());
	for(P ele:d){
		int tmp=(ele).second;
		if(tmp==1) num+=1;
		else num-=1;
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}