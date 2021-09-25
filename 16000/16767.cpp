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

typedef pair<int,int> P;

int n;
int start[101010];
int dur[101010];
vector<P> s;
priority_queue<int,vector<int>, greater<int> > pq;
int ans=0;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %d",start+i,dur+i);
		s.push_back(P(start[i],i));
	}
	if(n==1){puts("0");return 0;}
	sort(s.begin(),s.end());
	pq.push(s[0].second);
	int e=start[s[0].second];
	int cnt=1;
	while(1){
		int i=s[cnt].second;
		if(start[i]==e) {pq.push(i);cnt++;}
		else break;
	}
	while(!pq.empty()){
		int x=pq.top();
		pq.pop();
		if(e>start[x]) {ans=max(ans,e-start[x]);e+=dur[x];}
		else e=start[x]+dur[x];
		while(cnt<n){
			int i=s[cnt].second;
			if(start[i]<=e){
				pq.push(i);
				cnt++;
			}else if(pq.empty()){
				pq.push(i);
				cnt++;
				break;
			}else break;
		}
	}
	cout<<ans;
	return 0;
}