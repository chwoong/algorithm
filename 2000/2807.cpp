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

long long num[26][26];
int n;
long long ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int len=s.size();
		num[s[0]-'A'][s[len-1]-'A']++;
	}
	for(int i=0;i<26;i++){
		for(int j=i;j<26;j++){
			//i<j
			if(i!=j){
				for(int a=0;a<26;a++){
					for(int b=0;b<26;b++){
						if(a==b && a==i){
							ans+=2ll*num[a][j]*num[j][a]*num[a][i]*(num[a][i]-1);
						}else if(a==b && a==j){
							ans+=2ll*num[a][i]*num[i][a]*num[a][j]*(num[a][j]-1);
						}else if(a==i && b==j){
							ans+=2ll*num[a][i]*num[j][b]*num[i][b]*(num[i][b]-1);
						}else if(a==j && b==i){
							ans+=2ll*num[a][j]*num[i][b]*num[a][i]*(num[a][i]-1);
						}else{
							ans+=2ll*num[a][i]*num[a][j]*num[i][b]*num[j][b];
						}
					}
				}
			}else{
				long long x=0;
				long long y=0;
				for(int t=0;t<26;t++){
					x+=num[t][i]*(num[t][i]-1);
					y+=num[i][t]*(num[i][t]-1);
				}
				long long val=num[i][i]*(num[i][i]-1);
				ans+=(x*y-val*val);
				ans+=num[i][i]*(num[i][i]-1)*(num[i][i]-2)*(num[i][i]-3);
			}
		}
	}
	cout<<ans;
	return 0;
}