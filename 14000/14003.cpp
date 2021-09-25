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
int arr[1000000];

//len[i]: i번째 원소부터 시작하는 최대 증가 수열 길이
int len[1000000];

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	vector<int> v;
	len[n-1]=1;
	v.push_back(-arr[n-1]);
	for(int i=n-2;i>=0;i--){
		vector<int>::iterator it=lower_bound(v.begin(),v.end(),-arr[i]);
		if(it==v.end()){
			v.push_back(-arr[i]);
			len[i]=v.size();
		}
		else{
			*it=-arr[i];
			len[i]=(it-v.begin())+1;
		}
	}
	int ans=v.size();
	printf("%d\n",ans);
	for(int i=0;i<n;i++){
		if(len[i]==ans){
			printf("%d ",arr[i]);
			ans--;
		}
	}
	return 0;
}