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

int n,m,l,h;
vector<int> x;
vector<int> y;
long long sumy[300010];
map<int,int> mx;
long long ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		x.push_back(a);
		mx[a]=b;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		y.push_back(a);
		sumy[i]=sumy[i-1]+b;
	}
	cin>>l>>h;
	for(int i=0;i<n;i++){
		int id=x[i];
		long long val=mx[id];
		// (id+l) ~ (id+h)
		vector<int>::iterator it=lower_bound(y.begin(),y.end(),id+l);
		it--;
		int pos1=it-y.begin();
		it=lower_bound(y.begin(),y.end(),id+h+1);
		it--;
		int pos2=it-y.begin();
		long long s=sumy[pos2+1]-sumy[pos1+1];
		ans+=val*s;
	}
	cout<<ans;
	return 0;
}