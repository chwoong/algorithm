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
int arr[200010];
vector<int> l_one;
vector<int> l_zero;
vector<int> r_one;
vector<int> r_zero;
int numone;
long long ans=10000000000ll;
long long inversion(int i,int j){
	long long n=0;
	long long ret=0;
	for(int k=i;k<=j;k++){
		if(arr[k]) n++;
		else ret+=n;
	}
	return ret;
}

int main(){
	cin>>n;
	for(int i=0;i<n*2;i++){
		scanf("%d",arr+i);
		if(arr[i]) numone++;
	}
	for(int i=n-1;i>=0;i--){
		if(arr[i]) l_one.push_back(n-1-i);
		else l_zero.push_back(n-1-i);
	}
	for(int i=n;i<2*n;i++){
		if(arr[i]) r_one.push_back(i-n);
		else r_zero.push_back(i-n);
	}
	long long x=inversion(0,n-1);
	long long y=inversion(n,2*n-1);
	long long d=x-y;
	/*가운데에서 (1,0)->(0,1)*/
	/*의 행위를 최대 min(l_one.size, r_zero.size) 만큼 할 수 있다*/
	/*cnt번 한다고 하자. 그리고 부족한 차이는 인접한 0,1을 뒤바꾸는 행위로 메꿀수 있다.*/
	int cnt=min(l_one.size(),r_zero.size());
	ans=min(ans,abs(d));
	long long ret=0;
	for(int i=1;i<=cnt;i++){
		d+=(numone-n);
		d-=l_one[i-1];
		d+=r_zero[i-1];
		ret++;
		ret+=(l_one[i-1]+r_zero[i-1]);
		ans=min(ans,ret+abs(d));
	}
	/*가운데에서 (0,1)->(1,0)*/
	/*의 행위를 최대 min(l_zero.size, r_one.size) 만큼 할 수 있다*/
	cnt=min(l_zero.size(),r_one.size());
	d=x-y;
	ret=0;
	for(int i=1;i<=cnt;i++){
		d+=(n-numone);
		d+=l_zero[i-1];
		d-=r_one[i-1];
		ret++;
		ret+=(l_zero[i-1]+r_one[i-1]);
		ans=min(ans,ret+abs(d));
	}
	cout<<ans;
	return 0;
}