#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<string.h>
#include<set>
#include<stdlib.h>
using namespace std;
int n,m;
int sal[500001];
int fenwick[500010];
vector<int> ch[500001];
int cnt=1;
int dtn[500001];
int st[500001];
int en[500001];

void dfs(int i){
	dtn[i]=cnt;
	st[i]=cnt;
	cnt++;
	for(int ele:ch[i]){
		dfs(ele);
	}
	en[i]=cnt;
}

int sum(int pos){
	int s=0;
	while(pos>0){
		s+=fenwick[pos];
		pos-=(pos&-pos);
	}
	return s;
}
void update(int pos,int val){
	while(pos<=n){
		fenwick[pos]+=val;
		pos+=(pos&-pos);
	}
}

int main(){
	cin>>n>>m;
	scanf("%d",sal+1);
	for(int i=2;i<=n;i++){
		int x;
		scanf("%d %d",sal+i,&x);
		ch[x].push_back(i);
	}
	dfs(1);
	for(int i=0;i<m;i++){
		char s[10];
		scanf("%s",s);
		if(s[0]=='p'){
			int a,x;
			scanf("%d %d",&a,&x);
			//start[a]+1부터 n까지 쭉 다 더하고
			//end[a]부터 n까지 쭉 다 빼고
			//그럼 부하들만 월급 추가된다.
			update(st[a]+1,x);
			update(en[a],-x);
		}else{
			int a;
			scanf("%d",&a);
			printf("%d\n",sal[a]+sum(dtn[a]));
		}
	}
	return 0;
}