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
priority_queue<P,vector<P>,greater<P> > pq;
bool isused[100000];
int n;
string s;
string a="";
string b="";
int main(){
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++){
		pq.push(P(s[i],-i));
	}
	int cnt=n-1;
	while(!pq.empty()){
		while(isused[cnt]) cnt--;
		a+=s[cnt];
		isused[cnt]=true;
		cnt--;
		while(!pq.empty()){
			P here=pq.top();
			pq.pop();
			if(isused[-here.second]) continue;
			else{
				b+=s[-here.second];
				isused[-here.second]=true;
				break;
			}
		}
	}
	int x=a.compare(b);
	if(x>0) puts("DA");
	else puts("NE");
	cout<<b;
	cin>>s;
	return 0;
}