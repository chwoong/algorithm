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

#define MAX 100010
int fenwick[100020];
int n;
int order[100010];
int ans;
void update(int pos){
	while(pos<=MAX){
		fenwick[pos]+=1;
		pos+=(pos&-pos);
	}
}
int sum(int pos){
	int s=0;
	while(pos>0){
		s+=fenwick[pos];
		pos-=(pos&-pos);
	}
	return s;
}

int main(){
	cin>>n;
	n*=2;
	memset(order,-1,sizeof(order));
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(order[x]!=-1){
			//order[x]부터 끝까지 아직 경로가 완성이 안된 것이 몇개인지 카운팅하자 
			ans+=(i-order[x]-1)-(sum(i)-sum(order[x]));
			update(i);
			update(order[x]);
		}else{
			order[x]=i;
		}
	}
	cout<<ans;
	return 0;
}