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
int arr[100000];
int bit[100001];
vector<int> v;

void update(int pos,int val){
	while(pos<=n){
		bit[pos]+=val;
		pos+=(pos&-pos);
	}
}
int query(int pos){
	int ret=0;
	while(pos>0){
		ret+=bit[pos];
		pos-=(pos&-pos);
	}
	return ret;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
		v.push_back(arr[i]);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		arr[i]=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
		arr[i]++;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int l=query(n)-query(arr[i]);
		int r=n-arr[i]-l;
		update(arr[i],1);
		if(l>2*r || r>2*l) ans++; 
	}
	cout<<ans;
	return 0;
}