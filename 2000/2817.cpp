#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<string.h>
#include<set>
using namespace std;

typedef pair<double,int> P;
int m,n;
double d[26];
bool q[26]={0,};
int chip[26];
priority_queue<P> pq;
int main(){
	cin>>m>>n;
	for(int i=0;i<n;i++){
		char x;
		int y;
		cin>>x>>y;
		d[x-'A']=y;
	}
	for(int i=0;i<26;i++){
		if(d[i]>=(double)m*5.0/100.0){
			for(int j=1;j<=14;j++){
				pq.push(P(d[i]/j,i));
			}
			q[i]=true;
		}
	}
	for(int i=0;i<14;i++){
		P top=pq.top();
		pq.pop();
		chip[top.second]++;
	}
	for(int i=0;i<26;i++){
		if(q[i]){
			printf("%c %d\n",'A'+i,chip[i]);
		}
	}
	return 0;
}