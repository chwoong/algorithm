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

#define MAX 1000000000
int n;
int arr[5000];
bool visited[5000];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		arr[i]=x-1;
	}
	int ans=0;
	for(int i=1;i<n;i++){
		if(!visited[i]){
			ans++;
			for(int j=i;j<n;j++){
				if(arr[j]%arr[i]==0) visited[j]=true;
			}
		}
	}
	cout<<ans;
	return 0;
}