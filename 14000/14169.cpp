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
typedef pair<int,int> P;

int n,xl,yl,xb,yb;
int x[100010];
int y[100010];

vector<int> a;
vector<int> b;

bool visited[100010];
bool visited1[100010];
bool visited2[100010];
vector<int> p[100010];
vector<int> q[100010];

int main(){
	cin>>n>>xl>>yl>>xb>>yb;
	for(int i=0;i<n;i++){
		scanf("%d",x+i);
		scanf("%d",y+i);
		a.push_back(x[i]);
		b.push_back(y[i]);
	}
	x[n]=xb;
	y[n]=yb;
	x[n+1]=xl;
	y[n+1]=yl;
	a.push_back(x[n]);
	b.push_back(y[n]);
	a.push_back(x[n+1]);
	b.push_back(y[n+1]);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(int i=0;i<=(n+1);i++){
		x[i]=lower_bound(a.begin(),a.end(),x[i])-a.begin();
		y[i]=lower_bound(b.begin(),b.end(),y[i])-b.begin();
		p[x[i]].push_back(i);
		q[y[i]].push_back(i);
	}
	xl=x[n+1];
	yl=y[n+1];
	xb=x[n];
	yb=y[n];
	int ans=0;
	queue<P>qu;
	for(int ele:p[xl]){
		qu.push(P(x[ele],y[ele]));
		visited[ele]=true;
		visited1[xl]=true;
	}
	for(int ele:q[yl]){	
		qu.push(P(x[ele],y[ele]));
		visited[ele]=true;
		visited2[yl]=true;
	}
	while(!qu.empty()){
		int len=qu.size();
		for(int i=0;i<len;i++){
			P here=qu.front();
			qu.pop();
			if(here.first==xb && here.second==yb){
				cout<<ans;
				return 0;
			}
			if(!visited1[here.first]){
				for(int ele:p[here.first]){
					if(!visited[ele]){
						qu.push(P(x[ele],y[ele]));
						visited[ele]=true;
					}
				}
				visited1[here.first]=true;
			}
			if(!visited2[here.second]){
				for(int ele:q[here.second]){
					if(!visited[ele]){
						qu.push(P(x[ele],y[ele]));
						visited[ele]=true;
					}
				}
				visited2[here.second]=true;
			}
		}
		ans++;
	}
	cout<<-1;
	return 0;
}