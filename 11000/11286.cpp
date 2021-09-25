#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int,int> P;

priority_queue<P> pq;

int main(){
	int n,x;
	cin>>n;
	while(n--){
		scanf("%d",&x);
		/*추가*/
		if(x){
			if(x>0) pq.push(P(-x,-1));
			else pq.push(P(x,1));
		}
		/*절댓값 가장 작은 값 출력 및 제거*/
		else{
			if(pq.empty()) puts("0");
			else{
				P val=pq.top();
				pq.pop();
				printf("%d\n",val.first*val.second);
			}
		}
	}
	return 0;
}