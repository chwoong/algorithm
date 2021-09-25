#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

typedef pair<int,int> P; 

int main(){
	int N;
	int cover;
	cin>>N;
	priority_queue<P, vector<P>, greater<P> > pq;
	for(int i=0;i<N;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		pq.push(P(b,a));
	}
	int ans=1;
	cover=pq.top().first;
	pq.pop();
	while(!pq.empty()){
		P here=pq.top();
		pq.pop();
		if(here.second>=cover){
			cover=here.first;
			ans++;
		}else continue;
	}
	cout<<ans;
}