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
int up[100010];
int u[100010];
int down[100010];
int d[100010];
int fen[100010];
long long ans;

void update(int pos,int val){
	while(pos<=n){
		fen[pos]+=val;
		pos+=(pos&-pos);
	}
}
int sum(int pos){
	int s=0;
	while(pos>0){
		s+=fen[pos];
		pos-=(pos&-pos);
	}
	return s;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",up+i);
		u[up[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		down[x]=i;
		d[i]=x;
	}
	//처음 가로지르는 쌍 개수 구하기 by fenwick tree
	for(int i=1;i<=n;i++){
		ans+=(sum(n)-sum(down[up[i]]));
		update(down[up[i]],1);
	}
	//이제부터 한칸씩 옆으로 이동하면서 가로지르는 쌍의 수 개수 변화를 살펴보자
	long long tmp=ans;
	long long res=ans;
	/*길 왼쪽이동*/
	for(int i=1;i<=n;i++){
		//i번째가 가장 오른쪽으로 이동함
		tmp=tmp+(long long)(n-down[up[i]])-(long long)(down[up[i]]-1);
		res=min(tmp,res);
	}
	tmp=ans;
	/*길 오른쪽이동*/
	for(int i=1;i<=n;i++){
		//i번째가 가장 오른쪽으로 이동함
		tmp=tmp+(long long)(n-u[d[i]])-(long long)(u[d[i]]-1);
		res=min(tmp,res);
	}
	cout<<res;
	return 0;
}