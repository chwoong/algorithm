#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int n,m;
//v[i]: i번째 집합의 원소들
set <string> v[25];
//벤다이어 그램 : 각각의 동그라미를 각 성질을 갖고 있는 사람으로 생각하자.
//동그라미가 겹쳐서 교집합이 생기면 불가능한 경우이다.
//a성질과 b성질의 동그라미가 겹치는지 확인하기 위해서는
//25개의 사람의 분류 각각에 따라 a,b가 같이 들어가 있는 경우(1번)
//a에만 들어가 있는 경우(2번), b에만 들어가 있는 경우(3번)
//1,2,3번의 경우가 모두 있어야 된다.

set<string> s1;
vector<string> all;
bool intersect(int a0,int b0){
	int ab(0),a(0),b(0);
	for(int i=0;i<n;i++){
		bool hasa=false;
		bool hasb=false;
		if(v[i].count(all[a0])) hasa=true;
		if(v[i].count(all[b0])) hasb=true;
		if(hasa&&hasb) ab++;
		else if(hasa) a++;
		else if(hasb) b++;
	}
	return ab&&a&&b;
}
int main(){
	cin>>n;
	for(int p=0;p<n;p++){
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			v[p].insert(s);
			s1.insert(s);
		}
	}
	m=s1.size();
	for(set<string>::iterator it=s1.begin();it!=s1.end();it++){
		all.push_back(*it);
	}
	bool ans=true;
	for(int i=0;i<m-1;i++){
		for(int j=i+1;j<m;j++){
			//i,j성질에 대해 교집합이 존재하는지 확인하자.
			if(intersect(i,j)) ans=false;
		}
	}
	cout<<(ans?"yes":"no");
	return 0;
}