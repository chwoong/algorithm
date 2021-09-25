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

int n;
int arr[300000];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	int m=n;
	for(int i=n-1;i>=0;i--){
		if(arr[i]==m) m--;
	}
	cout<<m;
	return 0;
}