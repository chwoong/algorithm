#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

int N;
int map[6561][6561]={0,};

void solve(int i,int j,int size){
	/*±âÀú case*/
	if(size==3){
		map[i][j]=map[i][j+1]=map[i][j+2]=1;
		map[i+1][j]=map[i+1][j+2]=1;
		map[i+2][j]=map[i+2][j+1]=map[i+2][j+2]=1;
	}
	else{
		solve(i,j,size/3);
		solve(i,j+size/3,size/3);
		solve(i,j+2*size/3,size/3);
		
		solve(i+size/3,j,size/3);
		solve(i+size/3,j+2*size/3,size/3);
		
		solve(i+2*size/3,j,size/3);
		solve(i+2*size/3,j+size/3,size/3);
		solve(i+2*size/3,j+2*size/3,size/3);
	}
}

int main(){
	cin>>N;
	solve(0,0,N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(map[i][j]==1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}