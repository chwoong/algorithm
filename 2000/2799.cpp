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

int N,M;
int map[1000][1000];
int arr[5];
int main(){
	cin>>M>>N;
	for(int i=0;i<1+5*M;i++){
		string s;
		cin>>s;
		for(int j=0;j<1+5*N;j++){
			map[i][j]=s[j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int val=0;
			for(int k=0;k<4;k++){
				if(map[1+5*j+k][1+5*i]=='*') val++;
			}
			arr[val]++;
		}
	}
	for(int i=0;i<5;i++)
		cout<<arr[i]<<" ";
	return 0;
}