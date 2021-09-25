#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
long long save;
vector<vector<int>> bridge(123457);
long long sw[123457];

/* curr로 올수 있는 양의 수를 반환 */
long long dfs(int curr){
	long long ret=0;
	for(int next:bridge[curr]){
		ret+=dfs(next);
	}
	ret=max((long long)0,ret+sw[curr]);
	return ret;
}

int main(){
	scanf("%d\n",&N);
	char x;
	long long a;
	int p;
	sw[1]=0;
	for(int i=2;i<=N;i++){
		scanf("%c %lld %d\n",&x,&a,&p);
		bridge[p].push_back(i);
		if(x=='S') sw[i]=a;
		if(x=='W') sw[i]=-a;
	}
	
	printf("%lld",dfs(1));
	
	return 0;
}