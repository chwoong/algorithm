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
using namespace std;

int n;
int arr[100];
int ans;
int main(){
	cin>>n;
	memset(arr,-1,sizeof(arr));
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(arr[a]==-1) arr[a]=b;
		else if(arr[a]!=b){
			ans++;
			arr[a]=b;
		}
	}
	cout<<ans;
	return 0;
}