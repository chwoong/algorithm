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

typedef pair<double,int> P;
int n,m,k;
priority_queue<P> pq;
bool isused[101];
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int x;
			double y;
			scanf("%d %lf",&x,&y);
			pq.push(P(y,x));
		}
	}
	double ans=0;
	while(k){
		P here=pq.top();
		pq.pop();
		if(isused[here.second]) continue;
		else{
			isused[here.second]=true;
			k--;
			ans+=here.first;
		}
	}
	printf("%.1f",ans);
	return 0;
}