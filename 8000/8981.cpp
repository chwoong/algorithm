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

int n;
int arr[100];
int ans[100];
bool visited[100];
int main(){
	cin>>n;
	memset(ans,-1,sizeof(ans));
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	
	int count=0;
	int from=0;
	
	while(count<n){
		while(visited[from]){
			from=(from+1)%n;
		}
		visited[from]=true;
		ans[from]=arr[count];
		from=(from+ans[from])%n;
		count++;
	}
	printf("%d\n",n);
	for(int i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}