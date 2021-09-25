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

int n,k;
vector<int> v;
map<int,int> m;
vector<int> order;
vector<int> lis;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
		order.push_back(x);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		m[v[i]]=i/k;
	}
	for(int i=0;i<n;i++){
		order[i]=m[order[i]];
	}
	//order의 가장 긴 증가수열을 구하자
	for(int i=0;i<n;i++){
		if(lis.empty()) lis.push_back(order[i]);
		else{
			vector<int>:: iterator it=upper_bound(lis.begin(),lis.end(),order[i]);
			if(it==lis.end()) lis.push_back(order[i]);
			else *it=order[i];
		}
	}
	cout<<n-lis.size();
	return 0;
}