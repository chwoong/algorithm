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
int arr[100001];
vector<int> x;
vector<int> a[100001];
int base[100001];
//¾Ä¾î¹ö¸° Á¢½Ã Áß ÃÖ´ñ°ª
int r;
int ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	for(int i=0;i<n;i++){
		int v=arr[i];
		if(v<r) {ans=i;break;}
		for(int j=v;j>0 && base[j]==0; j--)
			base[j]=v;
		while(!a[base[v]].empty() && a[base[v]].back()<v){
			r=a[base[v]].back();
			a[base[v]].pop_back();
		}
		a[base[v]].push_back(v);
	}
	cout<<ans;
	return 0;
}