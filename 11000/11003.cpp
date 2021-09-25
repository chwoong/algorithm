/*
 *  author: chw0501
 *  created: 18.04.2020 01:55:51(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,l;
deque<P> dq;

int main(){
	cin>>n>>l;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(dq.empty()){
			dq.push_back(P(x,i));
			printf("%d ",x);
			continue;
		}else{
			if(dq.front().second<=i-l) dq.pop_front();
			while(!dq.empty() && dq.back().first>x) dq.pop_back();
			dq.push_back(P(x,i));
			printf("%d ",dq.front().first);
		}
	}
	return 0;
}