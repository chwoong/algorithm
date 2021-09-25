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

int t;
int main(){
	cin>>t;
	while(t--){
		int l,n;
		int low=0;
		int high=0;
		scanf("%d %d",&l,&n);
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			int a=min(x,l-x);
			int b=max(x,l-x);
			low=max(low,a);
			high=max(high,b);
		}
		printf("%d %d\n",low,high);
	}
	return 0;
}