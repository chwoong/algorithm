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

vector<int> adj[8000];
int dis[8000];
int cnt,scnt(1);
stack<int> st;
int sccid[8000];


int scc(int i){
	int ret=dis[i]=++cnt;
	st.push(i);
	for(int next:adj[i]){
		if(dis[next]==0) ret=min(ret,scc(next));
		else if(sccid[next]==0) ret=min(ret,dis[next]);
	}
	if(ret==dis[i]){
		while(!st.empty()){
			int h=st.top();
			sccid[h]=scnt;
			st.pop();
			if(h==i) break;
		}
		scnt++;
	}
	return ret;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=0;i<k;i++){
			int a,b,c,d;
			scanf("%d %d %d %d",&a,&b,&c,&d);
			a--; b--; c--; d--;
			b+=1000;
			d+=1000;
			if(a==c){
                if(b==d) continue;
				if(b<d) {
					adj[2*a].push_back(2*a+1);
					adj[2*c].push_back(2*c+1);
				}
				else{
					adj[2*a+1].push_back(2*a);
					adj[2*c+1].push_back(2*c);
				} 
				continue;
			}else if(b==d){
				if(a<c){
					adj[2*b].push_back(2*b+1);
					adj[2*d].push_back(2*d+1);
				}
				else{
					adj[2*b+1].push_back(2*b);
					adj[2*d+1].push_back(2*d);
				} 
				continue;
			}
			int x,y;
			x=(a<c)?1:0;
			y=(b<d)?1:0;
			adj[2*b+!x].push_back(2*a+y);
			adj[2*b+!x].push_back(2*d+x);
			adj[2*c+!y].push_back(2*a+y);
			adj[2*c+!y].push_back(2*d+x);
			
			adj[2*a+!y].push_back(2*b+x);
			adj[2*a+!y].push_back(2*c+y);
			adj[2*d+!x].push_back(2*b+x);
			adj[2*d+!x].push_back(2*c+y);
		}
		for(int i=0;i<2*n;i++){
			if(dis[i]==0) scc(i);
		}
		for(int i=0;i<2*m;i++){
			if(dis[2000+i]==0) scc(2000+i);
		}
		bool flag=true;
		for(int i=0;i<n;i++){
			if(sccid[i*2]==sccid[i*2+1]) flag=false;
		}
		for(int i=1000;i<1000+m;i++){
			if(sccid[i*2]==sccid[i*2+1]) flag=false;
		}
		if(flag) puts("Yes");
		else puts("No");
		
		//reset
		for(int i=0;i<8000;i++){
			adj[i].clear();
			dis[i]=0;
			sccid[i]=0;
		}
		cnt=0; scnt=1;
	}
	
	
	
	
	return 0;
}