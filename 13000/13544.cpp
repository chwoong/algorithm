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
int s(1);
vector<int> arr;
vector<int> v[400000];

void update(int l,int r,int node){
	if(l==r){
		v[node].push_back(arr[l]);
		return;
	}
	for(int i=l;i<=r;i++){
		v[node].push_back(arr[i]);
	}
	sort(v[node].begin(),v[node].end());
	int mid=(l+r)/2;
	update(l,mid,node*2);
	update(mid+1,r,node*2+1);
}
int query(int l,int r,int k){
	l+=s;
	r+=s;
	int num=0;
	while(l<=r){
		if(l%2==1){
			num+=v[l].size()-(lower_bound(v[l].begin(),v[l].end(),k+1)-v[l].begin());
			l++;
		}
		if(r%2==0){
			num+=v[r].size()-(lower_bound(v[r].begin(),v[r].end(),k+1)-v[r].begin());
			r--;
		}
		l/=2; r/=2;
	}
	return num;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		arr.push_back(x);
	}
	while(s<n) s*=2;
	for(int i=n;i<s;i++){
		arr.push_back(-1);
	}
	update(0,s-1,1);
	int m;
	cin>>m;
	int ans=0;
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a^=ans;b^=ans;c^=ans;
		a--; b--;
		//cout<<a<<' '<<b<<' '<<c<<endl;
		ans=query(a,b,c);
		printf("%d\n",ans);
	}
	return 0;
}