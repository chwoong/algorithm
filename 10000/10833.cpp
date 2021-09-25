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
using namespace std;

int N;
int main(){
	cin>>N;
	int ans=0;
	for(int i=0;i<N;i++){
		int s,a;
		scanf("%d %d",&s,&a);
		ans+=a%s;
	}
	cout<<ans;
	return 0;
}