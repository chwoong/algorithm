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
int t;
int id[100000];
int p[100000];
vector<int>l;
vector<int>r;
vector<int>d;
vector<P> result;
int main(){
	cin>>t;
	while(t--){
		l.clear();
		r.clear();
		d.clear();
		result.clear();
		int n,L,k;
		scanf("%d %d %d",&n,&L,&k);
		for(int i=0;i<n;i++){
			scanf("%d %d",p+i,id+i);
			if(id[i]>0){
				r.push_back(L-p[i]);
			}else{
				l.push_back(p[i]);
			}
		}
		int len=l.size();
		for(int i=0;i<len;i++) d.push_back(l[i]);
		len=r.size();
		for(int i=0;i<len;i++) d.push_back(r[i]);
		for(int i=0;i<n;i++){
			result.push_back(P(d[i],id[i]));
		}
		sort(result.begin(),result.end());
		printf("%d\n",result[k-1].second);
	}
	return 0;
}