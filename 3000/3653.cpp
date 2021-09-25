#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
using namespace std;

int n,m;
int ind[100001];
int fanwick[200001];

void update(int pos,int val){
	while(pos<=m+n){
		fanwick[pos]+=val;
		pos +=(pos & -pos);
	}
}
int sum(int pos){
	int ret=0;
	while(pos>0){
		ret+=fanwick[pos];
		pos -=(pos & -pos);
	}
	return ret;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		/*init*/
		memset(fanwick,0,sizeof(fanwick));
		for(int i=1;i<=n;i++){
			ind[i]=m+i;
			update(m+i,1);
		}
		/*몇번째에 무슨 영화를 보는가*/
		for(int j=1;j<=m;j++){
			int movie;
			scanf("%d ",&movie);
			printf("%d ",sum(ind[movie]-1));
			update(ind[movie],-1);
			ind[movie]=m+1-j;
			update(ind[movie],1);
		}
		printf("\n");
	}
	return 0;
}