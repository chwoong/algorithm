#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<set>
#include<stdlib.h>
#include<string>
#include<utility>
#include<stack>
using namespace std;

typedef pair<int,int> P;
int N;
int s[300010];
int m[300010];
vector<long long> v;
vector<P>cnt;
long long sum=0;
int main() {
	cin>>N;
	for(int i=0;i<N;i++)
		scanf("%d",s+i);
	for(int i=0;i<N;i++){
		long long x;
		scanf("%lld",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	for(int i=1;i<N-1;i++){
		if(s[i-1]>s[i] && s[i]<s[i+1]){
			cnt.push_back(P(i,-1));
		}else if(s[i-1]<s[i] && s[i]>s[i+1]){
			cnt.push_back(P(i,1));
		}
	}
	int f(0),e(N-1);
	for(P ele:cnt){
		if(ele.second>0){
			m[ele.first]=v[e];
			sum+=((long long)2*v[e--]);
		}else{
			m[ele.first]=v[f];
			sum-=((long long)2*v[f++]);
		}
	}
	if(s[0]<s[1]){
		m[0]=v[f];
		sum-=v[f++];
	}else{
		m[0]=v[e];
		sum+=v[e--];
	}
	if(s[N-1]<s[N-2]){
		m[N-1]=v[f];
		sum-=v[f++];
	}else{
		m[N-1]=v[e];
		sum+=v[e--];
	}
	cout<<sum<<endl;
	for(int i=1;i<N-1;i++){
		if(s[i-1]<s[i]&&s[i]<s[i+1]) m[i]=v[f++];
		if(s[i-1]>s[i]&&s[i]>s[i+1]) m[i]=v[e--];
	}
	for(int i=0;i<N;i++)
		printf("%d ",m[i]);
	return 0;	
}