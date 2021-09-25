#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<set>
#include<stack>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ans=0;
	while(n--){
		stack<int>st;
		char s[100001];
		scanf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]=='A') st.push(0);
			else st.push(1);
			while(!st.empty()){
				int f1,f2;
				f1=st.top();
				st.pop();
				if(!st.empty()) {
					f2=st.top();
					st.pop();
					if(f1!=f2)	{
						st.push(f2);
						st.push(f1);
						break;
					}
				}else{
					st.push(f1);
					break;
				}
				
			}
		}
		if(st.empty()) ans++;
	}
	cout<<ans;
	return 0;
}