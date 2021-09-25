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
vector<P>order;
priority_queue<int> pq;
int t=0;
int d[100];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		order.push_back(P(a,i));
		d[i]=b;
	}
	sort(order.begin(),order.end());
	for(int i=0;i<n;i++){
		int x=order[i].second;
		if(t<=order[i].first){
			t=order[i].first+d[x];
		}else{
			t+=d[x];
		}
	}
	cout<<t;
	return 0;
}