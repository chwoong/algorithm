#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
#include<string>
#include<string.h>

using namespace std;

typedef pair<long long,int>  P;
int n;
vector<P> b;
vector<P> a;
vector<P> ab;
long long bsum[500000];
//min1의 a선택 위치 저장
int ch1=0;
set<int> s;
//a_i-b_i의 최솟값 위치 저장
int ch2;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		long long x,y;
		scanf("%lld %lld",&x,&y);
		a.push_back(P(x,i));
		b.push_back(P(y,i));
		ab.push_back(P(x-y,i));
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	bsum[0]=b[0].first;
	for(int i=1;i<n;i++){
		bsum[i]=bsum[i-1]+b[i].first;
	}
	//k번째 줄
	cout<<a[ch1].first<<'\n';
	ch2=b[0].second;
	for(int k=2;k<=n;k++){
		//b_0~b_k-2와 나머지 중에 a 
		long long min1;
		//덮이면
		s.insert(b[k-2].second);
		if(b[k-2].second==a[ch1].second){
			while(s.count(a[ch1].second)){
				ch1++;
			}
		}
		min1=bsum[k-2]+a[ch1].first;
		//b_0~b_k-1와 그 사이에 a_i-b_i
		long long min2;
		int p=b[k-1].second;
		if(ab[ch2].first>ab[p].first) ch2=p;
		min2=bsum[k-1]+ab[ch2].first;
		printf("%lld\n",min(min1,min2));
	}
	return 0;
}