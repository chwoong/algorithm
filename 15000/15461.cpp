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
map<int,int> amount; //�ҵ��� ���귮 ����
multiset<int> s; //���� ���� �ҵ��� ���귮�� ������� ����(÷�� 0�� n�� ����)
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
		//�� ���� ���귮�� ���� ���� �ִ�.
		if(amount.count(id)){
			//���� �Ҹ� �����
			s.erase(s.find(amount[id]));
			//�ִ��� ���
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
			//�ִ��� �ƴ� ����ε� �ִ밡 �Ǵ� ���
			else if(amount[id]+d>=m){
				ans++;
				amount[id]+=d;
				m=amount[id];
			}
			//�ִ��� �ƴѵ� ���ص� ��� �ִ밡 �ƴ� ���
			else{
				amount[id]+=d;
			}
			s.insert(amount[id]);
		}
		//�� �Ҵ� ���귮�� 0�̴�.
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