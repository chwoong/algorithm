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

typedef pair<long long,long long> P;
int n,m,r;
vector<long long> milk;
vector<P> sellm; //��ũ �Ǹ�
vector<long long> sellc; //�� �Ǹ�
long long p[100010]; //��ũ �Ǹ�
long long q[100010]; //�� �Ǹ�
int main(){
	cin>>n>>m>>r;
	for(int i=0;i<n;i++){
		long long x;
		scanf("%lld",&x);
		milk.push_back(x);
	}
	sort(milk.begin(),milk.end(),greater<long long>() );
	for(int i=0;i<m;i++){
		long long a,b;
		scanf("%lld%lld",&a,&b);
		sellm.push_back(P(b,a));
	}
	sort(sellm.begin(),sellm.end(),greater<P>() );
	for(int i=0;i<r;i++){
		long long x;
		scanf("%lld",&x);
		sellc.push_back(x);
	}
	sort(sellc.begin(),sellc.end(),greater<long long>() );
	//���� ����ϰ� �ִ� ���� ������ ����
	int order=0;
	//���� ����ϰ� �ִ� ���� ���Կ� �Ǹ��� ��
	long long amount=0;
	for(int i=1;i<=n;i++){
		//�Ҹ� �Ǹ��� ���� i�����϶�
		if(i<=r) q[i]=q[i-1]+sellc[i-1];
		else q[i]=q[i-1];
		//�׸��� ���� ��ũ�� �Ǹ��� ���� i���� �϶�
		//���� ���� ���� ���귮
		long long s=milk[i-1];
		long long val=0;
		while(1){
			if(s==0) break;
			if(order==m) break;
			if(amount+s<=sellm[order].second){
				val+=s*sellm[order].first;
				amount+=s;
				break;
			}
			val+=(sellm[order].second-amount)*sellm[order].first;
			s-=(sellm[order].second-amount);
			amount=0;
			order++;
		}
		p[i]=p[i-1]+val;
	}
	long long ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,p[i]+q[n-i]);
	}
	cout<<ans;
	return 0;
}