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
#include <cstdio>
#include <fstream>
using namespace std;

int n,q;
struct S{
	int x1,x2,y,index;
	bool operator<(const S& tmp)const{
		if(x1==tmp.x1) return x2<tmp.x2;
		return x1<tmp.x1;
	}
};
vector<S> v;
int arr[100001];
int cnt=0;
int main(){
	cin>>n>>q;
	for(int i=0;i<n;i++){
		int x1,x2,y;
		scanf("%d %d %d",&x1,&x2,&y);
		v.push_back((S){x1,x2,y,i+1});
	}
	sort(v.begin(),v.end());
	int f=-1;
	for(int i=0;i<n;i++){
		if(v[i].x1>f){
			cnt++;
			arr[v[i].index]=cnt;
			f=max(f,v[i].x2);
		}else{
			arr[v[i].index]=cnt;
			f=max(f,v[i].x2);
		}
	}
	for(int i=0;i<q;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(arr[a]==arr[b]) puts("1");
		else puts("0");
	}
	return 0;
}