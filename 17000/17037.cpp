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
using namespace std;

int n,k;
int fenwick[1010][1010];
int sum;

void update(int x,int y,int val){
	int ypos=y;
	while(ypos<=1000){
		int xpos=x;
		while(xpos<=1000){
			fenwick[xpos][ypos]+=val;
			xpos+=(xpos& -xpos);
		}
		ypos+=(ypos & -ypos);
	}
}

int query(int x,int y){
	int s=0;
	int ypos=y;
	while(ypos>0){
		int xpos=x;
		while(xpos>0){
			s+=fenwick[xpos][ypos];
			xpos-=(xpos& -xpos);
		}
		ypos-=(ypos & -ypos);
	}
	return s;
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		a++; b++;
		update(a,b,1);
		update(c+1,b,-1);
		update(a,d+1,-1);
		update(c+1,d+1,1);
	}
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			if(query(i,j)==k) sum++;
		}
	}
	cout<<sum;
	return 0;
}