#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int alphabet[26]={0,};
/* 10^i계산 */
int calc(int i){
	int ret=1;
	for(int k=1;k<=i;k++)
		ret*=10;
	return ret;
}

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		/* 각 알파벳이 담고 있는 숫자를 구하자. */
		for(int j=0;j<s.size();j++){
			alphabet[s[j]-'A']+=calc(s.size()-1-j);
		}
	}	
	vector<int> val;
	for(int i=0;i<26;i++){
		if(alphabet[i]!=0) val.push_back(alphabet[i]);
	}
	sort(val.begin(),val.end(),greater<int>());
	int k=9;
	int m=0;
	for(int i=0;i<val.size();i++){
		m+=val[i]*k;
		k--;
	}
	cout<<m;
	return 0;
}