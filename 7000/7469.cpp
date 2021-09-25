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
#include<time.h>
using namespace std;

int n,m;
int s(1);
int arr[100000];
vector<int> num;
int com[100000];
map<int,int> rev;
vector<int> seg[400000];

void update(int pos,int val){
	pos+=s;
	seg[pos].push_back(val);
	for(pos/=2;pos>0;pos/=2){
		seg[pos].push_back(val);
	}
}
//[i,j]사이의 k번째 수
int kth(int i,int j,int k){
	int l0=-1;
	int h0=n-1;
	while(l0+1<h0){
		int mid=(l0+h0)/2;
		int st=i+s;
		int en=j+s;
		int res=0;
		while(st<=en){
			if(st%2==1) {res+=(upper_bound(seg[st].begin(),seg[st].end(),mid)-seg[st].begin()); st++;}
			if(en%2==0) {res+=(upper_bound(seg[en].begin(),seg[en].end(),mid)-seg[en].begin()); en--;}
			st/=2; en/=2;
		}
		if(res>=k) h0=mid;
		else l0=mid;
	}
	return h0;
}

int main(){
	cin>>n>>m;
	while(s<n) s*=2;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		arr[i]=x;
		num.push_back(x);
	}
	sort(num.begin(),num.end());
	//좌표압축
	for(int i=0;i<n;i++){
		com[i]=num[i];
		rev[num[i]]=i;
	}
	for(int i=0;i<n;i++){
		update(i,rev[arr[i]]);
	}
	for(int i=1;i<2*s;i++){
		sort(seg[i].begin(),seg[i].end());
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		int r=kth(a-1,b-1,c);
		printf("%d\n",com[r]);
	}
	return 0;
}