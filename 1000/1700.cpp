#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

int N,K;

int main(){
	cin>>N>>K;
	vector<int> order;
	for(int i=0;i<K;i++){
		int x;
		cin>>x;
		order.push_back(x);
	}
	/*현재 사용하고 있는 구멍 개수*/
	int l=0;
	/*현재 사용중인 전기용품 종류 */
	set<int> use;
	/*플러그 빼는 횟수*/
	int ans=0;
	for(int i=0;i<K;i++){
		/* 현재 써야하는 전기용품 */
		int here=order[i];
		if(l<N){
			set<int>::iterator it=use.find(here);
			if(it==use.end()) {use.insert(here); l++;}
		}
		else if(l==N){
			set<int>::iterator it=use.find(here);
			if(it!=use.end()) continue;
			/*없는 전기용품이면*/
			else{
				ans++;
				set<int>s(use);
				for(int j=i+1;j<K;j++){
					if(s.size()==1) break;
					else{
						set<int>::iterator iter=s.find(order[j]);
						if(iter!=s.end()) s.erase(*iter);
					}
				}
				/*s.begin()에 해당하는 원소를 바꾸자*/
				use.erase(*s.begin());
				use.insert(here);
			}
		}		
	}
	cout<<ans;
	return 0;
}