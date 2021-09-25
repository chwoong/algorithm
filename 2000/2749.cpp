/*
 *  author: chw0501
 *  created: 18.04.2020 01:25:06(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

#define MOD 1000000
/*행렬로 표현 후 분할 정복*/
ll n;
struct M{
	ll a,b,c,d;
	M(ll a_,ll b_,ll c_,ll d_):a(a_),b(b_),c(c_),d(d_){}
};

M f(M& i,M& j){
	ll a=i.a; ll b=i.b;
	ll c=i.c; ll d=i.d;
	ll a_=j.a; ll b_=j.b;
	ll c_=j.c; ll d_=j.d;
	return M((a*a_+b*c_)%MOD,(a*b_+b*d_)%MOD,(a_*c+d*c_)%MOD,(b_*c+d*d_)%MOD);
}

M solve(ll x){
	if(x==1){
		return M(1,1,1,0);
	}
	M tmp=M(1,1,1,0);
	M res=solve(x/2);
	M sq=f(res,res);
	if(x%2==1) return f(sq,tmp);
	else return sq;
}

int main(){
	cin>>n;
	if(n==1){
		puts("1");
		return 0;
	}
	M ans=solve(n-1);
	cout<<ans.a;
	return 0;
}