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
using namespace std;

typedef pair<int,int> P;
int n;
vector<P> v;
map<int,int> m;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v.push_back(P(b,a));
	}
	sort(v.begin(),v.end());
	for(int i=n-1;i>=0;i--){
		int x=v[i].second;
		int y=v[i].first;
		if(m.empty()) m[x]=y;
		else{
			map<int,int>::iterator it=m.lower_bound(x);
			if(it==m.end()){
				it--;
				int a=(*it).first;
				int b=(*it).second;
				if(b-x+a<y) m[x]=y;
			}
			else if(it==m.begin()){
				int a=(*it).first;
				int b=(*it).second;
				if(b-a+x<y) m[x]=y;
			}
			else{
				int a=(*it).first;
				int b=(*it).second;
				if(b-a+x>=y) continue;
				it--;
				a=(*it).first;
				b=(*it).second;
				if(b-x+a>=y) continue;
				m[x]=y;
			}
		}
	}
	cout<<m.size();
	return 0;
}