#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<utility>
#include<string>
#include<string.h>

using namespace std;

#define INF 1000000000
int n,R,M,K;
map<string,int> m;
double dist[100][100];
//내일로 사용하지 않는 가격
double cost1[100][100];
//내일로 사용하는 가격
double cost2[100][100];
int main(){
	cin>>n>>R;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		m[s]=i;
	}
	cin>>M;
	vector<int> order;
	for(int i=0;i<M;i++){
		string s;
		cin>>s;
		order.push_back(m[s]);
	}
	int len=order.size();
	cin>>K;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cost1[i][j]=INF;
			cost2[i][j]=INF;
		}
	}
	for(int i=0;i<K;i++){
		string t,s,e;
		double c;
		int a,b;
		cin>>t>>s>>e;
		cin>>c;
		a=m[s];
		b=m[e];
		if(t=="ITX-Saemaeul" || t=="ITX-Cheongchun" || t=="Mugunghwa"){
			cost2[a][b]=0;
			cost2[b][a]=0;
		}else if(t=="S-Train" || t=="V-Train"){
			cost2[a][b]=min(cost2[a][b],c/2);
			cost2[b][a]=min(cost2[b][a],c/2);
		}else{
			cost2[a][b]=min(cost2[a][b],c);
			cost2[b][a]=min(cost2[b][a],c);
		}
		cost1[a][b]=min(cost1[a][b],c);
		cost1[b][a]=min(cost1[b][a],c);
	}
	//입력 완료
	//내일로 사용 안할 경우
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dist[i][j]=(i==j?0:INF);
			if(cost1[i][j]!=INF) dist[i][j]=cost1[i][j];
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	double ans1=0;
	for(int i=0;i<len-1;i++){
		ans1+=dist[order[i]][order[i+1]];
	}
	//내일로 사용 하는 경우
	double ans2=R;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dist[i][j]=(i==j?0:INF);
			if(cost2[i][j]!=INF) dist[i][j]=cost2[i][j];
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	for(int i=0;i<len-1;i++){
		ans2+=dist[order[i]][order[i+1]];
	}
	if(ans1>ans2) puts("Yes");
	else puts("No");
	return 0;
}