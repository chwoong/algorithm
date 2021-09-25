#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		stack<int> s;
		string st;
		cin>>st;
		int len=st.size();
		int tmp=1;
		for(int i=0;i<len;i++){
			if(st[i]=='(') s.push(1);
			else{
				if(s.empty()) {
					tmp=0;
					cout<<"NO"<<'\n';
					break;
				}
				s.pop();
			}
		}
		if(tmp){
			if(s.empty()) cout<<"YES"<<'\n';
			else cout<<"NO"<<'\n';
		}
	}
	return 0;
}