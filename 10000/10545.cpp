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

int arr[10];
int alpha[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
//눌러야 하는 개수
int num[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int main(){
	for(int i=1;i<=9;i++){
		int x;
		scanf("%d",&x);
		arr[x]=i;
	}
	string s;
	cin>>s;
	int len=s.size();
	int prev=0;
	for(int i=0;i<len;i++){
		int here=alpha[s[i]-'a'];
		int n=num[s[i]-'a'];
		if(prev==here) printf("#");
		for(int j=0;j<n;j++)
			printf("%d",arr[here]);
		prev=here;
	}
	return 0;
}