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

int n,m(0);
string one[11]={"","one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
string two[9]={"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string three[8]={"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
vector<string>ans;
int k;
string change(int num){
	string ret="";
	if(num>=100){
		ret+=one[num/100];
		ret+="hundred";
		num%=100;
	}
	if(num==10) return ret+="ten";
	if(num>=11 && num<20){
		ret+=two[num-11];
		return ret;
	}else if(num>=20){
		ret+=three[num/10-2];
		num%=10;
	}
	ret+=one[num];
	return ret;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		ans.push_back(s);
		if(s!="$") m+=s.size();
		else k=i;
	}
	//m+f(x)=x 인 x를 찾는 것이 문제이다.
	//x>m 이다.
	for(int i=m+1;i<1000;i++){
		//i가 답인지 학인하자.
		string s=change(i);
		if(s.size()+m==i){
			for(int j=0;j<n;j++){
				if(j!=k) cout<<ans[j]<<' ';
				else cout<<s<<' ';
			}
			break;
		}
	}
	return 0;
}