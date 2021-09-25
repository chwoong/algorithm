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
vector<int> cow;
int ans1;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		cow.push_back(x);
	}
	sort(cow.begin(),cow.end());
	int cnt=0;
	for(int i=0;i<n;i++){
		//cow[i]부터 시작해서 cow[i]+n-1 까지 소가 몇마리 있는가
		while(cnt+1<n){
			if(cnt+1<n && cow[cnt+1]-cow[i]<n) cnt++;
			else break;
		}
		ans1=max(ans1,cnt-i+1);
	}
	if(cow[n-2]-cow[0]==n-2 && cow[n-1]-cow[n-2]>=3) puts("2");	
	else if(cow[n-1]-cow[1]==n-2 && cow[1]-cow[0]>=3) puts("2");
	else printf("%d\n",n-ans1);
	int x=cow[n-1]-cow[0]-(n-1);
	int y=min(cow[1]-cow[0],cow[n-1]-cow[n-2]);
	cout<<x-(y-1);

	
	return 0;
}