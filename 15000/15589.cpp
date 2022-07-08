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
int n;
vector<P> order;
long long ans;
long long finish;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		order.push_back(P(a,b));
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	sort(order.begin(),order.end());
	for(int i=0;i<n;i++){
		int s=order[i].first;
		int e=order[i].second;
		if(finish<=s){
			ans+=(e-s);
			finish=e;
		}else if(e>finish){
			ans+=(e-finish);
			finish=e;
		}
	}
	//���԰��谡 �ִ� �� Ȯ��
	bool include=false;
	for(int i=1;i<n;i++){
		if(order[i].second<order[i-1].second){
			include=true;
			break;
		}
	}
	if(include){
		cout<<ans;
		return 0;
	}
	//���԰��谡 ����
	//������ ȥ�ڸ� Ŀ���ϰ� �ִ� ������ ���̸� �������
	int alone_cover=1000000000;
	for(int i=0;i<n;i++){
		if(i==0){
			alone_cover=min(alone_cover,min(order[i+1].first,order[i].second)-order[i].first);
		}else if(i==n-1){
			alone_cover=min(alone_cover,order[i].second-max(order[i-1].second,order[i].first));
		}else{
			int x=max(order[i-1].second,order[i].first);
			int y=min(order[i+1].first,order[i].second);
			int val=max(0,y-x);
			alone_cover=min(alone_cover,val);
		}
	}
	cout<<ans-alone_cover;
	return 0;
}