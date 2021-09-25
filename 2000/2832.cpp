#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 100001
int fanwick[MAX];
int n;
long long cnt1,cnt2;
vector<int>v;

int query(int pos){
	int s=0;
	while(pos>0){
		s+=fanwick[pos];
		pos-=(pos&-pos);
	}
	return s;
}
void update(int pos){
	while(pos<MAX){
		fanwick[pos]+=1;
		pos+=(pos&-pos);
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	/*맨 처음 정렬*/
	vector<int>::iterator l,r;
	l=v.begin();
	r=v.begin();
	while(1){
		if(r+1!=v.end()){
			if(*(r+1)<*r) r++;
			else if(r-l>0){
				reverse(l,r+1);
				cnt1++;
				l=r+1;
				r=l;
			}else{
				l=r+1;
				r=l;
			}
		}else if(r-l>0){
			reverse(l,r+1);
			cnt1++;
			break;
		}else break;
	}
	/*그 다음부터의 정렬은 숫자 쌍 하나씩 변화한다.*/
	for(int i=0;i<n;i++){
		cnt2+=query(n)-query(v[i]);
		update(v[i]);
	}
	cout<<cnt1+cnt2<<endl;
	
}