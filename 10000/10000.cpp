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

struct Both{
	int l,r;
	Both(){}
	Both(int a,int b):l(a),r(b){}
	bool operator<(Both& x){
		if(l!=x.l) return l<x.l;
		else return r>x.r;
	}
};
int n;
vector<Both> endpo;
stack<Both> s;
int ans=1;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		endpo.push_back(Both(a-b,a+b));
	}
	sort(endpo.begin(),endpo.end());
	for(int i=0;i<n;i++){
		ans++;
		Both x=endpo[i];
		if(s.empty()){
			s.push(x);
		}else{
			Both a=s.top();
			while(a.l<x.l){
				s.pop();
				if(!s.empty()) a=s.top();
				else break;
			}
			if(!s.empty()){
				if(a.l==x.l){
					if(a.r==x.r){
						ans++;
					}else{
						s.pop();
						s.push(Both(x.r,a.r));
						s.push(Both(x.l,x.r));	
					}
				}else{
					s.push(x);
				}
			}else s.push(x);
		}
	}
	cout<<ans;
	return 0;
}