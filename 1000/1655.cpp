/*
 *  author: chw0501
 *  reference: 
 *  created: 19.04.2020 04:40:41(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

priority_queue<int,vector<int>,greater<int> > gp;
int g;
priority_queue<int> lp;
int l;
int mid;
int n,x;

int main(){
	cin>>n;
	scanf("%d",&x);
	mid=x;
	printf("%d\n",x);
	for(int i=0;i<n-1;i++){
		scanf("%d",&x);
		if(mid<=x) {gp.push(x); g++;}
		else {lp.push(x); l++;}
		if(g==l+2){
			lp.push(mid);
			mid=gp.top();
			gp.pop();
			l++; g--;
		}else if(l==g+1){
			gp.push(mid);
			mid=lp.top();
			lp.pop();
			l--; g++;
		}
		printf("%d\n",mid);
	}
	return 0;
}