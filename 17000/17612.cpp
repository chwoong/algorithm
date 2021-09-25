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

typedef pair<int,int> P;
struct person{
	int time,counter,id;
	person(int a,int b,int c):time(a),counter(b),id(c){}
};
bool operator<(person x,person y){
		if(x.time!=y.time) return x.time>y.time;
		else return x.counter<y.counter;
}
int n,k;
priority_queue<P,vector<P>,greater<P> > incus; //(계산대 기다리는 시간,계산대 index)
priority_queue<person> outcus; 
long long ans=0;
long long i=1;

int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		incus.push(P(0,i));
	}
	for(int i=0;i<n;i++){
		int id,w;
		scanf("%d %d",&id,&w);
		P here=incus.top();
		incus.pop();
		int cal=here.second;
		int wait=here.first;
		incus.push(P(wait+w,cal));
		outcus.push(person(wait+w,cal,id));
	}
	while(!outcus.empty()){
		person a=outcus.top();
		outcus.pop();
		ans+=i*(long long)a.id;
		i++;
	}
	cout<<ans;
	return 0;
}