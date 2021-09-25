#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m;
int a[100001]={0,};
int b[100001]={0,};
int x[100001]={0,};
bool isused[100001];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		a[x]++;
		b[y]++;
	}
	int tmp=1;
	for(int i=1;i<=n;i++){
		x[i]=a[i]+i-b[i];
		if(isused[x[i]]) {tmp=0;break;}
		isused[x[i]]=true;
	}
	if(tmp){
		for(int i=1;i<=n;i++)
			printf("%d ",x[i]);
	}else{
		cout<<-1;
	}
}