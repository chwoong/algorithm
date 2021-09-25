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
vector<int> v;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end(), greater<int>() );
	int cnt=0;
	for(int i=0;i<n;i++){
		if(cnt<=v[i]) cnt++;
	}
	cout<<cnt;
	return 0;
}