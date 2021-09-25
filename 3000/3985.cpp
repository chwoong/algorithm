#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;

int l,n;
bool v[1001];
int main(){
	cin>>l>>n;
	int em=0;
	int rm=0;
	int e;
	int r;
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(em<b-a){
			em=b-a;
			e=i;
		}
		int num=0;
		for(int j=a;j<=b;j++){
			if(!v[j]) {v[j]=true; num++;}
		}
		if(rm<num){
			rm=num;
			r=i;
		}
	}
	cout<<e<<endl;
	cout<<r;
	return 0;
}