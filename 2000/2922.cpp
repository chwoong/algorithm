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
//���� Ȯ���Ϸ��� ��ġ i(i==len�̸� ����), 'L'�� ����ߴ��� ����. �� ���� 2�� ���� ����. �϶� ������ ���� �� �ִ� ������
/*����
���� 0 �ڸ� 1 ���� 2 ��� 3 �ϰų� 4
*/
long long solve(int i,int u,int st){
	long long& ret=dp[i][u][st];
	if(ret!=-1ll) return ret;
	if(i==len){
		if(u==1) return ret=1ll;
		else return ret=0;
	}
	ret=0;
	//Ž�� ������ ���� ����
	if(st==4){
		if(s[i]=='_'){
			//����
			ret=(5ll*solve(i+1,u,1));
			//L�ƴ� ����
			ret+=(20ll*solve(i+1,u,2));
			//L����
			ret+=solve(i+1,1,2);
			return ret;
		}
		//L
		else if(s[i]=='L') return ret=solve(i+1,1,2);
		//L�ƴ� ����
		else if(alpha[s[i]-'A']==0) return ret=solve(i+1,u,2);
		//����
		else if(alpha[s[i]-'A']==1) return ret=solve(i+1,u,1);
	}
	//����
	else if(st==0){
		if(s[i]=='_'){
			//����
			ret=(5ll*solve(i+1,u,1));
			return ret;
		}
		//����
		else if(alpha[s[i]-'A']==0) return ret=0;
		//����
		else if(alpha[s[i]-'A']==1) return ret=solve(i+1,u,1);
	}
	//�ڸ�
	else if(st==1){
		if(s[i]=='_'){
			//����
			ret=(5ll*solve(i+1,u,3));
			//L�ƴ� ����
			ret+=(20ll*solve(i+1,u,2));
			//L����
			ret+=solve(i+1,1,2);
			return ret;
		}
		//L
		else if(s[i]=='L') return ret=solve(i+1,1,2);
		//L�ƴ� ����
		else if(alpha[s[i]-'A']==0) return ret=solve(i+1,u,2);
		//����
		else if(alpha[s[i]-'A']==1) return ret=solve(i+1,u,3);
	}
	//����
	else if(st==2){
		if(s[i]=='_'){
			//����
			ret=(5ll*solve(i+1,u,1));
			//L�ƴ� ����
			ret+=(20ll*solve(i+1,u,0));
			//L����
			ret+=solve(i+1,1,0);
			return ret;
		}
		//L
		else if(s[i]=='L') return ret=solve(i+1,1,0);
		//L�ƴ� ����
		else if(alpha[s[i]-'A']==0) return ret=solve(i+1,u,0);
		//����
		else if(alpha[s[i]-'A']==1) return ret=solve(i+1,u,1);
	}
	//���
	else if(st==3){
		if(s[i]=='_'){
			//L�ƴ� ����
			ret+=(20ll*solve(i+1,u,2));
			//L����
			ret+=solve(i+1,1,2);
			return ret;
		}
		//L
		else if(s[i]=='L') return ret=solve(i+1,1,2);
		//L�ƴ� ����
		else if(alpha[s[i]-'A']==0) return ret=solve(i+1,u,2);
		//����
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