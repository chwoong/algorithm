#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin>>N;
	vector<int> lis;
	lis.push_back(0);
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		if(lis.back()<x) lis.push_back(x);
		else *lower_bound(lis.begin(),lis.end(),x)=x;
	}
	cout<<lis.size()-1;
	return 0;
}