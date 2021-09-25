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
#define INF 1000000000
int r,c;
string str;
vector<P> l;
vector<P> x;
int ans;
bool visited[10000];
int mindist[10000];
map<int,int> m;

struct S{
	int a,b,c;
	bool operator<(const S tmp)const{
		return a<tmp.a;
	}
};

vector<S> info;
int d(P i,P j){
	return (i.first-j.first)*(i.first-j.first)+(i.second-j.second)*(i.second-j.second);
}

int main(){
	cin>>r>>c;
	for(int i=0;i<r;i++){
		cin>>str;
		for(int j=0;j<c;j++){
			if(str[j]=='L') l.push_back(P(i,j));
			else if(str[j]=='X') x.push_back(P(i,j));
		}
	}
	for(P i:l){
		for(P j:x){
			//l에는 가장 가까운 거리를 저장해놓고
			//x에는 가장 가까운 순서로 거리와 함께 l정보를 저장해놓자.
			int v=d(i,j);
			int lc=i.first*100+i.second;
			int xc=j.first*100+j.second;
			info.push_back((S){v,xc,lc});
		}
	}
	sort(info.begin(),info.end());
	for(S ele:info){
		//아직 x가 매칭이 안되어있으면
		if(!visited[ele.b]){
			if(mindist[ele.c]==0 || mindist[ele.c]==ele.a){
				mindist[ele.c]=ele.a;
				m[ele.c]++;
				visited[ele.b]=true;
			}
		}
	}
	for(auto it:m)
		if(it.second>=2) ans++;
	cout<<ans;
	return 0;
}