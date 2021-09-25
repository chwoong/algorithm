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

int main(){
	int l,p;
	cin>>l>>p;
	for(int i=0;i<5;i++){
		int x;
		scanf("%d",&x);
		printf("%d ",x-l*p);
	}
	return 0;
}