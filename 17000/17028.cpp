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
#include<utility>
#include<stack>
using namespace std;

int n;
vector<int>v;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	int tmp=1;
	for(int i=n-1;i>=1;i--){
		if(v[i]>v[i-1]) tmp++;
		else break;
	}
	cout<<n-tmp;
	return 0;
}