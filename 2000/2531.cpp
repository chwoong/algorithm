#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>
using namespace std;

int arr[30001];
int num[3001]={0,};
int n,d,k,c;
int main(){
	cin>>n>>d>>k>>c;
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	//쭉 돌면서 최대한 여러가지의 초밥을 먹고, visited[c]를 확인해서 0이면 하나 더 추가
	//연속한 초밥 k개를 먹어야 됨
	int ans=0;
	int ret=0;
	num[c]=100000;
	ret=1;
	for(int i=0;i<k;i++){
		if(num[arr[i]]==0) ret++;
		num[arr[i]]+=1;
	}
	ans=ret;
	if(k<n)
	for(int i=k;i<=n+k-2;i++){
		int a=arr[i-k];
		int b=arr[i%n];
		if(a==c && b==c) continue;
		else if(a==c && b!=c){
			num[b]+=1;
			if(num[b]==1) ret++;
		}else if(a!=c && b==c){
			num[a]-=1;
			if(num[a]==0) ret--;
		}else{
			if(a==b) continue;
			num[a]-=1;
			num[b]+=1;
			if(num[b]==1) ret++;
			if(num[a]==0) ret--;
		}
		ans=max(ans,ret);
	}
	cout<<ans;
	return 0;
}