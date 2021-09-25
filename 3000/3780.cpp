#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
using namespace std;
typedef pair<int,int> P;

int p[20001];
int dist[20001];

int len(int i){
	return i>=0?i%1000:(-i)%1000;
}

P find(int n){
	if(p[n]<0) return P(n,0);
	P next=find(p[n]);
	p[n]=next.first;
	dist[n]+=next.second;
	return P(p[n],dist[n]);
}

void merge(int c,int i){
	if(find(c).first==find(i).first) return;
	p[c]=i;
	dist[c]=len(c-i);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		memset(p,-1,sizeof(p));
		memset(dist,0,sizeof(dist));
		while(1){
			char order;
			scanf(" %c",&order);
			if(order=='O') break;
			/*거리 출력*/
			else if(order=='E'){
				int x;
				scanf("%d",&x);
				printf("%d\n",find(x).second);
			}
			/*merge*/
			else{
				int c,i;
				scanf("%d %d",&c,&i);
				merge(c,i);
			}
		}
	}
	return 0;
}