#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int,int> P;
vector<P>v;
int num;
int map[10][10];
int ans=25;
int ret=0;
int arr[6];
void col(int i,int j,int t,int val){
	for(int x=i;x<i+t;x++)
		for(int y=j;y<j+t;y++)
			map[x][y]=val;
}

void solve(){
	/*i,j를 다음 1에 갖다 놓자*/
	int k,i,j;
	for(k=0;k<num;k++){
		i=v[k].first;
		j=v[k].second;
		if(map[i][j]==1) break;
	}
	if(k==num) {
		ans=min(ret,ans);
		return;
	}
	if(ret>=ans) return;
	int x,y,tmp;
	/*5*5로 채울 수 있을까*/
	if(arr[5]<5 && i<=5 && j<=5){
		tmp=1;
		for(x=i;x<i+5;x++){
			for(y=j;y<j+5;y++){
				if(map[x][y]==0) tmp=0;
			}
		}
		if(tmp){
			ret+=1;
			arr[5]+=1;
			col(i,j,5,0);
			solve();
			ret-=1;
			arr[5]-=1;
			col(i,j,5,1);
		}
	}
	/*4*4로 채울 수 있을까*/
	if(arr[4]<5&& i<=6 && j<=6){
		tmp=1;
		for(x=i;x<i+4;x++){
			for(y=j;y<j+4;y++){
				if(map[x][y]==0) tmp=0;
			}
		}
		if(tmp){
			ret+=1;
			arr[4]+=1;
			col(i,j,4,0);
			solve();
			col(i,j,4,1);
			ret-=1;
			arr[4]-=1;
		}
	}
	/*3*3로 채울 수 있을까*/
	if(arr[3]<5 && i<=7 && j<=7){
		tmp=1;
		for(x=i;x<i+3;x++){
			for(y=j;y<j+3;y++){
				if(map[x][y]==0) tmp=0;
			}
		}
		if(tmp){
			ret+=1;
			arr[3]+=1;
			col(i,j,3,0);
			solve();
			col(i,j,3,1);
			ret-=1;
			arr[3]-=1;
		}
	}
	/*2*2로 채울 수 있을까*/
	if(arr[2]<5 && i<=8 && j<=8){
		tmp=1;
		for(x=i;x<i+2;x++){
			for(y=j;y<j+2;y++){
				if(map[x][y]==0) tmp=0;
			}
		}
		if(tmp){
			ret+=1;
			arr[2]+=1;
			col(i,j,2,0);
			solve();
			col(i,j,2,1);
			ret-=1;
			arr[2]-=1;
		}
	}
	/*1*1로 채울 수 있을까*/
	if(arr[1]<5 && i<=9 && j<=9){
		tmp=1;
		for(x=i;x<i+1;x++){
			for(y=j;y<j+1;y++){
				if(map[x][y]==0) tmp=0;
			}
		}
		if(tmp){
			ret+=1;
			arr[1]+=1;
			col(i,j,1,0);
			solve();
			col(i,j,1,1);
			ret-=1;
			arr[1]-=1;
		}
	}
}

int main(){
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]==1) v.push_back(P(i,j));
		}
	num=v.size();
	solve();
	printf("%d",ans==25?-1:ans);
	return 0;
}