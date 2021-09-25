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

int t;
int main(){
	cin>>t;
	for(int p=1;p<=t;p++){
		string s;
		int k;
		cin>>s;
		cin>>k;
		int arr[1000];
		int len=s.size();
		for(int i=0;i<len;i++){
			arr[i]=(s[i]=='+'?1:0);
		}
		int num=0;
		for(int i=0;i<=len-k;i++){
			if(arr[i]==1) continue;
			else{
				num++;
				for(int j=i;j<i+k;j++){
					arr[j]^=1;
				}
			}
		}
		bool tmp=true;
		for(int i=len-k+1;i<len;i++){
			if(arr[i]==0) tmp=false;
		}
		if(tmp){
			printf("Case #%d: %d\n",p,num);
		}else{
			printf("Case #%d: IMPOSSIBLE\n",p);
		}
	}
	return  0;
}