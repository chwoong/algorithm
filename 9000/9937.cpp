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

typedef pair<long long,long long> P;
#define MOD 1000000007
struct Line{
	long long a,b;
	bool operator<(const Line& x){return b*x.a<a*x.b;}
}line[300000];
int n,x,y;
vector<int> num;
int val=1;
long long one,two,ans;
int main(){
	cin>>n;
	int cnt=0;
	for(int i=0;i<n;i++){
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a==0) x++;
		else if(b==0) y++;
		else if(a<0){
			line[cnt].a=-a;
			line[cnt].b=-b;
			cnt++;
		}else{
			line[cnt].a=a;
			line[cnt].b=b;
			cnt++;
		}
	}
	sort(line,line+cnt);
	num.push_back(x);
	num.push_back(y);
	if(cnt==0) {puts("0");return 0;}
	P prev=P(line[0].a,line[0].b);
	for(int i=1;i<cnt;i++){
		P here=P(line[i].a,line[i].b);
		if(here.first*prev.second==prev.first*here.second) val++;
		else{
			num.push_back(val);
			val=1;
			prev=here;
		}
	}
	num.push_back(val);
	int len=num.size();
	for(int i=0;i<len;i++){
		ans=(ans+(two*num[i])%MOD)%MOD;
		two=(two+(one*num[i])%MOD)%MOD;
		one=(one+num[i])%MOD;	
	}
	cout<<ans;
	return 0;
}