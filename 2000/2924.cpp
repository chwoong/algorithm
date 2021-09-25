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
#include<time.h>
using namespace std;

int n,c,d;
long long a,b;
int p[500001];
//k번째 숫자가 포함된 cycle의 주기
int cycle[500001];

long long gcd(long long i,long long j){
	if(i>j) swap(i,j);
	if(i==0) return j;
	return gcd(i,j%i);
}

long long lcm(long long i,long long j){
	long long g=gcd(i,j);
	return i*j/g;
}

int main(){
	cin>>n;
	cin>>a>>b;
	cin>>c>>d;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		p[i]=x;
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		//아직 주기 안 찾은 원소에 대해
		if(cycle[i]==0){
			q.push(i);
			int next=p[i];
			while(next!=i){
				q.push(next);
				next=p[next];
			}
			int len=q.size();
			while(!q.empty()){
				cycle[q.front()]=len;
				q.pop();
			}
		}
	}
	long long g=1;
	for(int i=c+1;i<=n-d;i++){
		g=lcm(g,cycle[i]);
	}
	cout<<(b+g-1)/g-(a+g-2)/g;
	return 0;
}