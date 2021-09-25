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
int arr[500000];
vector<int> v;
int bit[500001];
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
		int x;
		scanf("%d",&x);
		arr[i]=x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		int x=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
		arr[i]=x+1;
	}
	//arr[i]: 1~n
	for(int i=0;i<n;i++){
		//arr[i]볻 큰 값 개수 +1
		int val=query(n)-query(arr[i]);
		printf("%d\n",val+1);
		update(arr[i],1);
	}
	return 0;
}