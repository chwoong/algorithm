#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
#include<stack>
using namespace std;

/*i번째 직사각형을 포함하는 최대 넓이를 구하는
스위핑 알고리즘 with stack*/
int main(){
	int n;
	long long h[100001];
	while(1){
		stack<int> remain;
		long long ans=0;
		scanf("%d",&n);
		if(n==0) break;
		for(int i=0;i<n;i++){
			scanf("%lld",h+i);
		}
		h[n]=0;
		for(int i=0;i<=n;i++){
			while(!remain.empty()){
				int j=remain.top();
				if(h[j]>h[i]){
					remain.pop();
					if(remain.empty()) ans=max(ans,h[j]*i);
					else ans=max(ans,h[j]*(i-remain.top()-1));
				}else if(h[j]==h[i]){
					remain.pop();
				}else break;
			}
			remain.push(i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}