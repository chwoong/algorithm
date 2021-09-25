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

string s;
int len;
int alpha[26];
long long dp[101][2][5];
//현재 확인하려는 위치 i(i==len이면 종료), 'L'을 사용했는지 여부. 그 앞의 2개 문자 종류. 일때 앞으로 나올 수 있는 가짓수
/*상태
자자 0 자모 1 모자 2 모모 3 암거나 4
*/
long long solve(int i,int u,int st){
	long long& ret=dp[i][u][st];
	if(ret!=-1ll) return ret;
	if(i==len){
		if(u==1) return ret=1ll;
		else return ret=0;
	}
	ret=0;
	//탐색 시작할 때의 상태
	if(st==4){
		if(s[i]=='_'){
			//모음
			ret=(5ll*solve(i+1,u,1));
			//L아닌 자음
			ret+=(20ll*solve(i+1,u,2));
			//L자음
			ret+=solve(i+1,1,2);
			return ret;
		}
		//L
		else if(s[i]=='L') return ret=solve(i+1,1,2);
		//L아닌 자음
		else if(alpha[s[i]-'A']==0) return ret=solve(i+1,u,2);
		//모음
		else if(alpha[s[i]-'A']==1) return ret=solve(i+1,u,1);
	}
	//자자
	else if(st==0){
		if(s[i]=='_'){
			//모음
			ret=(5ll*solve(i+1,u,1));
			return ret;
		}
		//자음
		else if(alpha[s[i]-'A']==0) return ret=0;
		//모음
		else if(alpha[s[i]-'A']==1) return ret=solve(i+1,u,1);
	}
	//자모
	else if(st==1){
		if(s[i]=='_'){
			//모음
			ret=(5ll*solve(i+1,u,3));
			//L아닌 자음
			ret+=(20ll*solve(i+1,u,2));
			//L자음
			ret+=solve(i+1,1,2);
			return ret;
		}
		//L
		else if(s[i]=='L') return ret=solve(i+1,1,2);
		//L아닌 자음
		else if(alpha[s[i]-'A']==0) return ret=solve(i+1,u,2);
		//모음
		else if(alpha[s[i]-'A']==1) return ret=solve(i+1,u,3);
	}
	//모자
	else if(st==2){
		if(s[i]=='_'){
			//모음
			ret=(5ll*solve(i+1,u,1));
			//L아닌 자음
			ret+=(20ll*solve(i+1,u,0));
			//L자음
			ret+=solve(i+1,1,0);
			return ret;
		}
		//L
		else if(s[i]=='L') return ret=solve(i+1,1,0);
		//L아닌 자음
		else if(alpha[s[i]-'A']==0) return ret=solve(i+1,u,0);
		//모음
		else if(alpha[s[i]-'A']==1) return ret=solve(i+1,u,1);
	}
	//모모
	else if(st==3){
		if(s[i]=='_'){
			//L아닌 자음
			ret+=(20ll*solve(i+1,u,2));
			//L자음
			ret+=solve(i+1,1,2);
			return ret;
		}
		//L
		else if(s[i]=='L') return ret=solve(i+1,1,2);
		//L아닌 자음
		else if(alpha[s[i]-'A']==0) return ret=solve(i+1,u,2);
		//모음
		else if(alpha[s[i]-'A']==1) return ret=0;
	}
}

int main(){
	cin>>s;
	len=s.size();
	if(len==1){
		if(s[0]=='_') cout<<1;
		else if(s[0]=='L') cout<<1;
		else cout<<0;
	}else if(len==2){
		if(s[0]=='_' && s[1]=='_') cout<<51;
		else if(s[0]=='_' && s[1]=='L') cout<<26;
		else if(s[0]=='L' && s[1]=='_') cout<<26;
		else if(s[0]=='_' || s[1]=='_') cout<<1;
		else if(s[0]=='L' || s[1]=='L') cout<<1;
		else cout<<0;
	}
	alpha['A'-'A']=1;
	alpha['E'-'A']=1;
	alpha['I'-'A']=1;
	alpha['O'-'A']=1;
	alpha['U'-'A']=1;
	memset(dp,-1ll,sizeof(dp));
	cout<<solve(0,0,4);
	return 0;
}