#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int a[50];
int b[50];
int main(){
	a[0]=1;
	b[0]=0;
	int k;
	cin>>k;
	for(int i=1;i<=k;i++){
		a[i]=b[i-1];
		b[i]=a[i-1]+b[i-1];
	}
	cout<<a[k]<<' '<<b[k];
	return 0;
}