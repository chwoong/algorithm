#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<string.h>
#include<set>
#include<stdlib.h>
#include<string>
using namespace std;

long long N;
string word;
int K;
long long num[1000010][26];
int main(){
	cin>>N>>word>>K;
	long long len=word.size();
	for(int i=0;i<len;i++){
		for(int j=0;j<26;j++){
			num[i+1][j]=num[i][j];
		}
		num[i+1][word[i]-'A']++;
	}
	
	for(int i=0;i<K;i++){
		long long a;
		long long ans=0;
		char s[10];
		scanf("%lld %s",&a,s);
		int h=s[0]-'A';
		long long st,fi;
		if(a%2==0){
			st=(a/2)%len;
			fi=(a/2)%len;
			st=(st*((a-1)%len))%len;
			fi=(fi*((a+1)%len))%len;
		}else{
			st=((a-1)/2)%len;
			fi=((a+1)/2)%len;
			st=(st*(a%len))%len;
			fi=(fi*(a%len))%len;
		}
		if(fi) fi--;
		else fi=len-1;
		//°è»ê
		if(st<=fi){
			//st~fi
			ans+=(num[fi+1][h]-num[st][h]);
			ans+=num[len][h]*((a-(fi-st+1))/len);
		}else{
			ans+=(num[len][h]-num[st][h]);
			ans+=(num[fi+1][h]);
			ans+=num[len][h]*((a-(len+fi-st+1))/len);
		}
		printf("%lld\n",ans);
	}
	return 0;
}