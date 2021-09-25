#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int N;
/*arr[0]=-1*/
int arr[100010];

int solve(int i){
	vector<int> v;
	int ret=0;
	/* 최대 감소 수열 */
	v.push_back(arr[0]);
	for(int i=1;i<=N;i++){
		if(v.back()<arr[i]){
			v.push_back(arr[i]);
			ret++;
		}else{
			vector<int>::iterator it=lower_bound(v.begin(),v.end(),arr[i]);
			*it=arr[i];
		}
	}
	return ret;
}

int main(){
	cin>>N;
	/*최대 증가 수열 길이*/
	int len;
	/*최대 증가 수열*/
	arr[0]=-1;
	for(int i=1;i<=N;i++)
		scanf("%d ",&arr[i]);
	len=solve(0);
	cout<<N-len;
	return 0;
}