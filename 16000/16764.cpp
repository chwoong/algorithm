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

long long in_ex[5]={1,-1ll,1,-1ll,1};
struct S{
	int num;
	int arr[5]={0,0,0,0,0};
};
bool operator<(S x,S y){
	for(int i=0;i<5;i++){
		if(x.arr[i]<y.arr[i]) return true;
		else if(x.arr[i]>y.arr[i]) return false;
	}
	return false;
}
long long n;
vector<int> v[50010];
map<S,long long> m;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++) {
			int x;
			scanf("%d",&x);
			v[i].push_back(x);
		}
		sort(v[i].begin(),v[i].end());
		for(int j=1;j<32;j++){
			//subset생성해서 map에 저장
			S tmp;
			int x=0;
			for(int k=0;k<5;k++){
				if(j&(1<<k)){
					tmp.arr[x++]=v[i][k];
				}
			}
			tmp.num=x;
			m[tmp]++;
		}
	}

	long long ans=n*(n-1)/2;
	//전체에서 pair개수를 빼자
	for(auto& x:m){
		int num=(x.first).num;
		long long val=x.second;
		ans-=in_ex[num-1]*val*(val-1)/2;
	}
	cout<<ans;
	return 0;
}