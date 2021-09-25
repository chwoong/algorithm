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
int n,g;
P info[1000010];
priority_queue<P,vector<P>,greater<P> > pq;
int m=0;
map<int,int> amount; //소들의 생산량 저장
multiset<int> s; //값이 변한 소들의 생산량을 순서대로 보관(첨에 0을 n개 저장)
int ans;

int main(){
	cin>>n>>g;
	for(int i=0;i<n;i++){
		int t,id,d;
		scanf("%d %d %d",&t,&id,&d);
		pq.push(P(t,i));
		info[i]=P(id,d);
		s.insert(0);
	}
	for(int i=0;i<n;i++){
		P now=pq.top();
		pq.pop();
		int id=info[now.second].first;
		int d=info[now.second].second;
		//그 소의 생산량이 변한 적이 있다.
		if(amount.count(id)){
			//변한 소를 지우고
			s.erase(s.find(amount[id]));
			//최댓값일 경우
			if(amount[id]==m){
				set<int>::iterator it=s.end();
				it--;
				if(*(it)!=amount[id]&& *(it)<amount[id]+d){
					amount[id]+=d;
					m=amount[id];
				}else{
					ans++;
					amount[id]+=d;
					m=max(amount[id],*it);
				}
			}
			//최댓값이 아닐 경우인데 최대가 되는 경우
			else if(amount[id]+d>=m){
				ans++;
				amount[id]+=d;
				m=amount[id];
			}
			//최댓값이 아닌데 변해도 계속 최대가 아닌 경우
			else{
				amount[id]+=d;
			}
			s.insert(amount[id]);
		}
		//그 소는 생산량이 0이다.
		else{
			amount[id]=d;
			s.insert(amount[id]);
			if(d>m || (d==m && m!=0)) ans++;
			else if(m==0) ans++;
			m=max(m,d);
		}
	}
	cout<<ans;
	return 0;
}