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
int n,m;
struct S{
	int st,en,id,w;
	bool operator<(S &tmp)const{
		if(st!=tmp.st) return st<tmp.st;
		else{
			return en>tmp.en;
		}
	}
};
vector<S>v;
multiset<int> s;
bool bus[500001];

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		bus[i]=true;
		int a,b;
		scanf("%d %d",&a,&b);
		if(a<b){
			v.push_back((S){a,b,i,1});
			v.push_back((S){b,0,i,-1});
			v.push_back((S){a+n,b+n,i,1});
			v.push_back((S){b+n,0,i,-1});
		}else{
			v.push_back((S){a,b+n,i,1});
			v.push_back((S){b+n,0,i,-1});
		}
	}
	sort(v.begin(),v.end());
	int len=v.size();
	for(int i=0;i<len;i++){
		if(v[i].w==1){
			if(!s.empty() && v[i].en<=*s.rbegin()){
				bus[v[i].id]=false;
			}
			s.insert(v[i].en);
		}else{
			s.erase(s.find(v[i].st));
		}
	}
	for(int i=1;i<=m;i++)
		if(bus[i]) printf("%d\n",i);
	return 0;
}