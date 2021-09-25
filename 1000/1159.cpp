#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int alpha[26];
int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		alpha[s[0]-'a']++;
	}
	int num=0;
	for(int i=0;i<26;i++){
		if(alpha[i]>=5) {printf("%c",'a'+i);num++;}
	}
	if(num==0) puts("PREDAJA");
	return 0;
}