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

#define MAX 1000000000
int n,q;
map<int,int> m;

void update(int pos){
	while(pos<=MAX){
		m[pos]++;
		pos+=(pos&-pos);
	}
}

int sum(int pos){
	int s=0;
	while(pos>0){
		s+=m[pos];
		pos-=(pos&-pos);
	}
	return s;
}

int main(){
	cin>>n>>q;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		update(x);
	}
	for(int i=0;i<q;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",sum(b)-sum(a-1));
		
	}
	return 0;
}