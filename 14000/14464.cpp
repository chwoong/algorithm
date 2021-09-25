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

typedef  pair<int,int> P;
int ans;
int c,n;
vector<int> chi;
vector<P> cow;
int main(){
	cin>>c>>n;
	for(int i=0;i<c;i++){
		int x;
		scanf("%d",&x);
		chi.push_back(x);
	}
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		cow.push_back(P(a,b));
	}
	sort(chi.begin(),chi.end());
	sort(cow.begin(),cow.end());
	int i=0;
	priority_queue<P,vector<P>, greater<P> > pq;
	for(int j=0;j<c;j++){
		while(1){
			if(i==n) break;
			if(cow[i].first<=chi[j] && chi[j]<=cow[i].second){
				pq.push(P(cow[i].second,cow[i].first));
				i++;
			}
			else if(chi[j]<cow[i].first) break;
			else if(chi[j]>cow[i].second) i++;
		}
		while(!pq.empty()){
			P x=pq.top();
			pq.pop();
			if(x.second<=chi[j] && chi[j]<=x.first) {ans++;break;}
			
		}
	}
	cout<<ans;
	return 0;
}