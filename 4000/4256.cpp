#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/* vector를 a번째에서 b번째까지 쪼갠다. */
vector<int> slice(const vector<int>& v,int a,int b){
	vector<int> ret(v.begin()+a,v.begin()+b+1);
	return ret;
}

void printpost(const vector<int>& pre,const vector<int>& in){
	if(pre.size()==0) return;
	/* 전위 순회 시 맨 앞이 root다 */
	int root=pre[0];
	int size=pre.size();
	int len=find(in.begin(),in.end(),root)-in.begin();
	printpost(slice(pre,1,len),slice(in,0,len-1));
	printpost(slice(pre,len+1,size-1),slice(in,len+1,size-1));
	cout<< root<< " ";
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> preorder;
		vector<int> inorder;
		int x;
		for(int i=0;i<n;i++){
			cin>>x;
			preorder.push_back(x);
		}
		for(int i=0;i<n;i++){
			cin>>x;
			inorder.push_back(x);
		}
		printpost(preorder,inorder);
		cout<<endl;
	}
	return 0;
}