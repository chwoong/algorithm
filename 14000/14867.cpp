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
int a,b,c,d;
/*상태수가 a*b일거라 생각할 수 있지만 최대 2*(a+b)개이다.*/
map<P,int> m;
queue<P> q;
int main(){
	cin>>a>>b>>c>>d;
	if(0<c && c<a && 0<d && d<b){puts("-1"); return 0;}
	m[{0,0}]=1;
	q.push({0,0});
	while(!q.empty()){
		P here=q.front();
		q.pop();
		int num=m[here];
		int x=here.first;
		int y=here.second;
		//물 비움
		if(m[{x,0}]==0) {m[P(x,0)]=num+1;q.push({x,0});}
		if(m[{0,y}]==0) {m[P(0,y)]=num+1;q.push({0,y});}
		//물 채움
		if(m[{a,y}]==0) {m[P(a,y)]=num+1;q.push({a,y});}
		if(m[{x,b}]==0) {m[P(x,b)]=num+1;q.push({x,b});}
		//물 옮김
		int l=min(a-x,y);
		if(m[{x+l,y-l}]==0) {m[P(x+l,y-l)]=num+1;q.push({x+l,y-l});}
		l=min(x,b-y);
		if(m[{x-l,y+l}]==0) {m[P(x-l,y+l)]=num+1;q.push({x-l,y+l});}
	}
	if(m[{c,d}]) cout<<m[{c,d}]-1;
	else cout<<-1;
	return 0;
}