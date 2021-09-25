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
#include<time.h>
using namespace std;

int m;
int k;
int arr[8][8];
//(i,j)기준으로 단위 구역 총합
int val[8][8];
int val2[8][8];
int res[8][8];

int comp[8][8];
int p[8][8];

int main(){
	cin>>m>>k;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	//단위 구역의 합이 홀수이면 그곳에는 뭔가가 뿌려지긴 했다.
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			int a=0;
			for(int x=0;x<8;x++)
				a+=arr[i][x];
			for(int x=0;x<8;x++)
				a+=arr[x][j];
			a-=arr[i][j];
			if((m*15-a)%2==1 || (a-m*15)%2==1){
				p[i][j]=1;
				for(int x=0;x<8;x++){
					comp[x][j]++;
				}
				for(int x=0;x<8;x++){
					comp[i][x]++;
				}
				comp[i][j]--;
			}
			val[i][j]=a;
		}
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			int a=0;
			for(int x=0;x<8;x++){
				a+=comp[i][x];
			}
			for(int x=0;x<8;x++){
				a+=comp[x][j];
			}
			a-=comp[i][j];
			val2[i][j]=a;
		}
	}
	//다른 지역에서 뿌리는 용액은 현재보려고 하는 (i,j)에서 
	//mod 4로 불변하다.
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(p[i][j]==1){
				int q=m*15+val2[i][j]-val[i][j];
				if(q<0) q=-q;
				if(p[i][j]==1 && q%4==2) res[i][j]=-1;
				else if(p[i][j]==1) res[i][j]=1;
			}
		}
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(res[i][j]==0) printf(". ");
			else if(res[i][j]==1) printf("+ ");
			else printf("- ");
		}
		cout<<endl;
	}
	return 0;
}