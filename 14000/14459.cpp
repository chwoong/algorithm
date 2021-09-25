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

int n;
int sz(1);
int a[100000];
int b[100000];
int s[100000]; //오른쪽 길의 목장의 i 소의 목초지가 몇번째에 있는가
int seg[400000];

void update(int pos,int val){
	pos+=sz;
	seg[pos]=val;
	for(pos/=2;pos>0;pos/=2)
		seg[pos]=max(seg[pos*2],seg[pos*2+1]);
}

int query(int l,int r){
	l+=sz;
	r+=sz;
	int ret=0;
	while(l<=r){
		if(l%2==1) ret=max(ret,seg[l++]);
		if(r%2==0) ret=max(ret,seg[r--]);
		l/=2; r/=2;
	}
	return ret;
}

int main(){
	cin>>n;
	while(sz<n) sz*=2;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		a[i]--;
	}
	for(int i=0;i<n;i++){
		scanf("%d",b+i);
		b[i]--;
		s[b[i]]=i;
	}
	//왼쪽 길의 i번째 목초지의 친한 소들 부터 오른쪽으로 매칭
	//이 떄 segment tree를 이용할텐데 구간 [l,r]의 segment tree의 반환값은
	//그 구간내에서 매칭할 수 있는 최대 횡단보도 수이다.
	for(int i=0;i<n;i++){
		vector<int> f;
		f.clear();
		//j는 a[i]의 친구
		for(int j=max(0,a[i]-4);j<=min(n-1,a[i]+4);j++){
			f.push_back(s[j]);
		}
		sort(f.begin(),f.end());
		//i의 친구중에 높은 index에 있는 친구부터 구간 update
		int len=f.size();
		for(int k=len-1;k>=0;k--){
			//m값은 구간 [0,v[k]-1] 의 최대 횡단보도 개수
			int m=query(0,f[k]-1);
			//f[k]값을 m+1으로 수정해야 한다.
			update(f[k],m+1);
		}
	}
	cout<<query(0,n-1);
	return 0;
}