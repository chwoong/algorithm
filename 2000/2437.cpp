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
#include <cstdio>
#include <fstream>
using namespace std;

int n;
vector<int> v;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int len=v.size();
	int cover=1; //cover-1 까지 커버 가능 
	for(int i=0;i<len;i++){
		if(v[i]>cover) break;
		else{
			cover=cover+v[i];
		}
	}
	cout<<cover;
	return 0;
}