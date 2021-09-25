#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<set>
#include<stdlib.h>
#include<string>
using namespace std;

int N;
vector<int> v;
int arr[100010];
bool iscoming[100010];
int start=1;
int len;
int mlen=0;
bool pos=true;
int ans;
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		scanf("%d",arr+i);
	}
	arr[N]=1;
	for(int i=0;i<N+1;i++){
		if(arr[i]>=0 && pos){
			continue;
		}
		else if(arr[i]>=0 &&!pos){
			if(mlen<len){
				v.clear();
				v.push_back(start);
				mlen=len;
			}else if(mlen==len){
				v.push_back(start);
			}
			for(int j=start;j>=max(1,start-2*len+1);j--){
				if(iscoming[j]==false){
					iscoming[j]=true;
					ans++;
				}
			}
			pos=1;
		}
		else if(arr[i]<0 && pos){
			start=i;
			pos=0;
			len=1;
		}else if(arr[i]<0 && !pos){
			len++;
		}
	}
	int ans1=0;
	for(int ele:v){
		int tmp=0;
		for(int i=ele-2*mlen+1;i>=max(1,ele-3*mlen+1);i--){
			if(iscoming[i]==false){
				tmp++;
			}
			ans1=max(ans1,tmp);
		}
	}
	cout<<ans+ans1;
	return 0;
}