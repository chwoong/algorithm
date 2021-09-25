/*
 *  author: chw0501
 *  reference: 
 *  created: 18.04.2020 07:07:50(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
int arr[1000];

//i번째 원소를 포함한 왼쪽부터의 최대 증가수열 길이
int len1[1000];
int len2[1000];

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	vector<int> v;
	v.push_back(arr[0]);
	len1[0]=1;
	for(int i=1;i<n;i++){
		vector<int>::iterator it=lower_bound(v.begin(),v.end(),arr[i]);
		if(it==v.end()){
			v.push_back(arr[i]);
			len1[i]=v.size();
		}else{
			*it=arr[i];
			len1[i]=(it-v.begin())+1;
		}
	}
	v.clear();
	v.push_back(arr[n-1]);
	len2[n-1]=1;
	for(int i=n-2;i>=0;i--){
		vector<int>::iterator it=lower_bound(v.begin(),v.end(),arr[i]);
		if(it==v.end()){
			v.push_back(arr[i]);
			len2[i]=v.size();
		}else{
			*it=arr[i];
			len2[i]=(it-v.begin())+1;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,len1[i]+len2[i]-1);
	}
	cout<<ans;
	return 0;
}