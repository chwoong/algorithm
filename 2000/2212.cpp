#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

int main(){
	int N,K;
	vector<int> v;
	cin>>N>>K;
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	/*�ִ� ����*/
	int len=v[N-1]-v[0];
	/*������ ���� ���� �Ÿ� ����*/
	vector<int> dist;
	for(int i=0;i<N-1;i++){
		int a=v[i+1]-v[i];
		dist.push_back(a);
	}
	sort(dist.begin(),dist.end(),greater<int>() );
	for(int i=1;i<min(N,K);i++){
		len-=dist[i-1];
	}
	cout<<max(0,len);
	return 0;
}