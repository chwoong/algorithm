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
		/*�߰�*/
		if(x){
			if(x>0) pq.push(P(-x,-1));
			else pq.push(P(x,1));
		}
		/*���� ���� ���� �� ��� �� ����*/
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