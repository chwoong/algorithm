#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>
#include<cmath>

using namespace std;

#define INF 100000000
typedef pair<int,int> P;
vector<P> adj[1001];
priority_queue<P,vector<P>,greater<P>> pq;
vector<int> dist_xtoi(1001,INF);
/* i�������� x�������� ���� �Ÿ� ���� �̿��ϴ� ���ͽ�Ʈ�� �ʿ��� vector */
vector<int> dist_itox(1001,INF);
/* i�������� x�������� ���� �Ÿ� ���� */
vector<int> dist_i(1001);

int main(){
	int n,m,x;
	cin>>n>>m>>x;
	int u,v,w;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		adj[u].push_back(P(v,w));
	}
	
	// ù��° ���ͽ�Ʈ�� 
	// X���� ������ ������ ���µ��� �ִܰŸ� ���
	dist_xtoi[x]=0;
	pq.push(P(0,x));
	while(!pq.empty()){
		int cost=pq.top().first;
		int here=pq.top().second;
		pq.pop();
		// �� ª�� ��ΰ� ����Ǿ������� ���� Ž���� �����ϰ� ������ �ٽ� ���� 
		if(dist_xtoi[here]<cost) continue;
		// ���� ���� Ž��
		for(int i=0;i<adj[here].size();i++){
			int there=adj[here][i].first;
			int nextdist=adj[here][i].second+cost;
			if(nextdist<dist_xtoi[there]){
				dist_xtoi[there]=nextdist;
				pq.push(P(nextdist,there));
			}
		}
	}
	
	
	// �ι�° ���ͽ�Ʈ�� 
	// ������ �������� x�� ���µ��� �ִܰŸ� ��� 
	for(int i=1;i<=n;i++){
		priority_queue<P,vector<P>,greater<P>> pq1;
		dist_itox[i]=0;
		pq1.push(P(0,i));
		while(!pq1.empty()){
			int cost=pq1.top().first;
			int here=pq1.top().second;
			pq1.pop();
			//���ͽ�Ʈ�� �߿� x���� �湮�ϸ� ���� 
			if(here==x) {dist_i[i]=dist_itox[here]; break;}
			if(dist_itox[here]<cost) continue;
			//���� ���� Ž��
			for(int i=0;i<adj[here].size();i++){
				int there=adj[here][i].first;
				int nextdist=adj[here][i].second+cost;
				if(nextdist<dist_itox[there]){
					dist_itox[there]=nextdist;
					pq1.push(P(nextdist,there));
				}
			}
		}
		//���� Ž���� ����� vector �ʱ�ȭ
		for(int j=1;j<=n;j++){
			dist_itox[j]=INF;
		}
	}
	
	
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(i==x) continue;
		tmp=max(tmp,dist_xtoi[i]+dist_i[i]);
	}
	cout<<tmp;
	
	return 0;
}