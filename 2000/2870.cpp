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

struct Word{
	string s;
	Word(string x):s(x){}
	bool operator <(const Word x){
		int a=s.size();
		int b=(x.s).size();
		if(a==b){
			return s.compare(x.s)<0;
		}else return a<b;
	}
};
int n;
vector<Word> ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int len=s.size();
		string ret="";
		for(int j=0;j<len;j++){
			if(s[j]>='a' && s[j]<='z') {Word w(ret); ans.push_back(w);ret="";}
			else if(s[j]=='0'){
				if(ret=="") ret+='0';
				else if(ret=="0") ret="0";
				else ret+='0';
			}else{
				if(ret=="0"){
					ret="";
					ret+=s[j];
				}else ret+=s[j];
			}
		}
		Word w(ret); 
		ans.push_back(ret);
	}
	sort(ans.begin(),ans.end());
	for(vector<Word>::iterator it=ans.begin();it!=ans.end();it++){
		if((*it).s!="") cout<<(*it).s<<endl;
	}
	return 0;
}