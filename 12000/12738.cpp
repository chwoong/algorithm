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


int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	vector<int> v;
	v.push_back(arr[0]);
	for(int i=1;i<n;i++){
		vector<int>::iterator it=lower_bound(v.begin(),v.end(),arr[i]);
		if(it==v.end()) v.push_back(arr[i]);
		else *it=arr[i];
	}
	cout<<v.size();
	return 0;
}