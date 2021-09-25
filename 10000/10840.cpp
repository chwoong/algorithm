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
using namespace std;

set<vector<int> >s;
string a,b;
int n,m;
vector<int> v(26,0);
int ans=0;
int main(){
	cin>>a;
	cin>>b;
	n=a.size();
	m=b.size();
	int len=min(n,m);
	//길이 i의 같은 성분을 가진 구간이 있는지 확인하자
	for(int i=1;i<=len;i++){
		for(int x=0;x<26;x++)
			v[x]=0;
		s.clear();
		for(int j=0;j<i;j++){
			v[a[j]-'a']++;
		}
		s.insert(v);
		//a의 j번째원소를 추가하자.(당연히 j-i번째 원소 삭제)
		for(int j=i;j<n;j++){
			v[a[j]-'a']++;
			v[a[j-i]-'a']--;
			s.insert(v);
		}
		//이제 b를 훑으면서 같은 성분 구간이 있는지 확인
		for(int x=0;x<26;x++)
			v[x]=0;
		for(int j=0;j<i;j++){
			v[b[j]-'a']++;
		}
		if(s.count(v)) {ans=max(ans,i); continue;}
		for(int j=i;j<m;j++){
			v[b[j]-'a']++;
			v[b[j-i]-'a']--;
			if(s.count(v)) {ans=max(ans,i); break;}
		}
	}
	cout<<ans;
	return 0;
}