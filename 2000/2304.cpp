#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector <pair<int,int>> pil;
	for(int i=0;i<N;i++){
		int pos, height;
		cin >> pos >> height;
		pil.push_back(make_pair(pos,height));
	}
	sort(pil.begin(),pil.end());
	stack<int> left,right;
	
	left.push(0);
	right.push(N-1);
	for(int i=1;i<N;i++){
		if(pil[i].second>pil[left.top()].second) left.push(i); 
	}
	for(int i=N-2;i>=0;i--){
		if(pil[i].second>pil[right.top()].second) right.push(i); 
	}
	int area(0);
	area += (pil[right.top()].first-pil[left.top()].first+1)*pil[right.top()].second;
	while(1){
		int tmp =left.top();
		left.pop();
		if(!left.empty()) area += (pil[tmp].first-pil[left.top()].first)*pil[left.top()].second;
		else break;
	}
	while(1){
		int tmp =right.top();
		right.pop();
		if(!right.empty()) area -= (pil[tmp].first-pil[right.top()].first)*pil[right.top()].second;
		else break;
	}
	cout << area;
	
	return 0;
}