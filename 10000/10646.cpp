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
#include<time.h>
using namespace std;

#define EVEN 1
#define ODD 0
string s;
int len;

int main(){
	cin>>s;
	len=s.size();
	int iseven=0;
	if((s[0]-'0')%2==0) iseven=EVEN;
	for(int i=1;i<len;i++){
		int x=s[i]-'0';
		int here;
		if(x%2==1) here=ODD;
		else here=EVEN;
		if(iseven!=here){
			iseven=here;
			continue;
		}else{
			//처음으로 홀짝성이 틀린 위치
			//마지막 위치에서 안바뀜(i위치에서 바뀜)
			{
				if(x==0){
					string ans="";
					for(int j=0;j<i;j++) ans+=s[j];
					bool flag=true;
					for(int j=i;j<len;j++){
						if(flag) ans+="1";
						else ans+="0";
						flag=!flag;
					}
					cout<<ans;
				}else if(x==9){
					string ans="";
					for(int j=0;j<i;j++) ans+=s[j];
					bool flag=true;
					for(int j=i;j<len;j++){
						if(flag) ans+="8";
						else ans+="9";
						flag=!flag;
					}
					cout<<ans;
				}else{
					if(here==EVEN){
						string ans="";
						for(int j=0;j<i;j++) ans+=s[j];
						string tmp="";
						bool flag=true;
						for(int j=i+1;j<len;j++){
							if(flag) tmp+="4";
							else tmp+="5";
							flag=!flag;
						}
						string a=s.substr(i+1);
						string b="";
						string c="";
						flag=true;
						for(int j=i+1;j<len;j++){
							if(flag) b+="0";
							else b+="1";
							flag=!flag;
						}
						flag=true;
						for(int j=i+1;j<len;j++){
							if(flag) c+="8";
							else c+="9";
							flag=!flag;
						}
						int val=a.compare(tmp);
						if(val<0){
							ans+=(s[i]-1);
							ans+=c;
							cout<<ans;
						}else if(val==0){
							string k=ans;
							k+=(s[i]-1);
							k+=c;
							cout<<k<<' ';
							k=ans;
							k+=(s[i]+1);
							k+=b;
							cout<<k;
						}else{
							ans+=(s[i]+1);
							ans+=b;
							cout<<ans;
						}
					}else{
						string ans="";
						for(int j=0;j<i;j++) ans+=s[j];
						string tmp="";
						bool flag=true;
						for(int j=i+1;j<len;j++){
							if(flag) tmp+="5";
							else tmp+="4";
							flag=!flag;
						}
						string a=s.substr(i+1);
						string b="";
						string c="";
						flag=true;
						for(int j=i+1;j<len;j++){
							if(flag) b+="1";
							else b+="0";
							flag=!flag;
						}
						flag=true;
						for(int j=i+1;j<len;j++){
							if(flag) c+="9";
							else c+="8";
							flag=!flag;
						}
						int val=a.compare(tmp);
						if(val<0){
							ans+=(s[i]-1);
							ans+=c;
							cout<<ans;
						}else if(val==0){
							string k=ans;
							k+=(s[i]-1);
							k+=c;
							cout<<k<<' ';
							k=ans;
							k+=(s[i]+1);
							k+=b;
							cout<<k;
						}else{
							ans+=(s[i]+1);
							ans+=b;
							cout<<ans;
						}
					}
				}
			}
		}
		return 0;
	}
	
	return 0;
}