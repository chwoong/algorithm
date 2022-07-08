#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include<math.h>
using namespace std;

#define INF 1000000000
typedef pair<double,int> P;
typedef pair<double,double> Pd;
/*i�������� ���� �ð��� ������ ���� ������ �����ϰ� �ִ� vector*/
vector<P> adj[102];
/*i������ ��ǥ�� ����
0�� ���� ������, 1�� ���� ������
2�������� N+1�� ������ */
vector<Pd> v;
int N;
double plen[102];
priority_queue<P, vector<P>, greater<P> > pq;

double d(int a,int b){
	return  sqrt((v[a].first-v[b].first)*(v[a].first-v[b].first)+(v[a].second-v[b].second)*(v[a].second-v[b].second));
}
double dist(int a,int b){
	double x=d(a,b);
	//�������Ǵ� ���������� ���
	if(a==0 || a==1){
		return x/5.0;
	}
	//�������� �������Ǵ� ������
	if(b==0||b==1){
		if(x>=50){
			return (x-50)/5.0+2;
		}
		return min(2+(50-x)/5.0,x/5.0);
	}
	//��������
	if(x>=50){
		return 2+(x-50)/5.0;
	}else{
		return min(x/5.0,2+(50-x)/5.0);
	}
}
int main(){
	double a,b;
	//������
	scanf("%lf %lf",&a,&b);
	v.push_back(Pd(a,b));
	//������
	scanf("%lf %lf",&a,&b);
	v.push_back(Pd(a,b));
	cin>>N;
	for(int i=0;i<N;i++){
		scanf("%lf %lf",&a,&b);
		v.push_back(Pd(a,b));
	}
	/*�� ���� ������ �Ÿ� ���ϱ�*/
	for(int i=0;i<=N+1;i++){
		for(int j=0;j<=N+1;j++)
			if(i!=j) adj[i].push_back(P(dist(i,j),j));
		plen[i]=INF;
	}
	plen[0]=0;
	pq.push(P(0,0));
	while(!pq.empty()){
		P curr=pq.top();
		pq.pop();
		int here=curr.second;
		double cost=curr.first;
		if(cost>plen[here]) continue;
		for(P next: adj[here]){
			int there=next.second;
			double nextcost=next.first+cost;
			if(nextcost<plen[there]){
				plen[there]=nextcost;
				pq.push(P(nextcost,there));
			}
		}
	}
	printf("%.6f",plen[1]);
	return 0;
}