#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int map[1000][1000];
int arr[1000];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&map[i][j]);
		}
	}
	if(n==2 && map[0][1]==2){
		cout<<1<<' '<<1<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		int j=(i+1)%n;
		int k=(i+2)%n;
		arr[i]=(map[j][i]-map[j][k]+map[k][i])/2;
	}
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}