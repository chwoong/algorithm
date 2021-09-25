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

typedef pair<int,int> P;
int n,c;
map<int,int> arr;
map<int,int> order;
int rev[1000];
int cnt;
vector<P> v;
int main(){
	cin>>n>>c;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		//처음 나온 거면
		if(arr[x]==0) {
			order[x]=cnt;
			rev[cnt]=x;
			cnt++;
		}
		arr[x]++;
	}
	for(P ele:arr){
		P t=P(ele.second,-order[ele.first]);
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	int len=v.size();
	for(int i=len-1;i>=0;i--){
		int j=v[i].first;
		int num=rev[-v[i].second];
		while(j--){
			printf("%d ",num);
		}
	}
	
	return 0;
}