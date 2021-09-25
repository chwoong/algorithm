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
#define INF 3000000000000
typedef pair<int,long long> P;
int N,st,en;
struct OB{
	int x,y[2];
};
bool operator<(OB a,OB b){
	return a.x<b.x;
}
vector<OB> v;
set<P>s;
vector<int> a;
long long ans=INF;
int main(){
	cin>>N;
	cin>>st>>en;
	for(int i=0;i<N;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		OB ob={a,{b,c}};
		v.push_back(ob);
	}
	sort(v.begin(),v.end());
	s.insert(P(st,0));
	for(int i=0;i<N;i++){
		set<P>::iterator iter1,it;
		int yl=v[i].y[0];
		int yh=v[i].y[1];
		//yl이상의 가장 작은 y값
		it=s.lower_bound(P(yl,0));
		vector<P> m;
		while(it!=s.end()){
			int y=(*it).first;
			if(y>=yh) break;
			long long len=(*it).second;
			m.push_back(P(yl,-(len+y-yl)));
			m.push_back(P(yh,len+yh-y));
			set<P>::iterator tmp=it;
			it++;
			s.erase(tmp);
		}
		if(!m.empty()){
			P f=m.front();
			s.insert(P(f.first,-f.second));
			s.insert(m.back());
		}
	}
	set<P>::iterator it;
	for(it=s.begin();it!=s.end();it++){
		if((*it).second <ans){
			ans=(*it).second;
			vector<int> q;
			swap(a,q);
			a.push_back((*it).first);
		}else if((*it).second==ans) a.push_back((*it).first);
	}
	printf("%lld\n",ans+en);
	printf("%d ",(int)a.size());
	for(int ele:a)
		printf("%d ",ele);
}