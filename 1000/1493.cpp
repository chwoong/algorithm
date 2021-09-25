#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

long long l,w,h;
int N;
vector<pair<int,int>> box;
int use=0;
int cnt=0;
void divide(long long x,long long y,long long z){
	if(x==0 || y==0|| z==0) return;
	int n=-1;
	for(int i=N-1;i>=0&&cnt==0;i--){
		long long len=1ll<<box[i].first;
		if(box[i].second>0 && len<=x && len<=y && len<=z && cnt==0){
			n=0;
			box[i].second--;
			use++;
			divide(x,y,z-len);
			divide(x-len,y,len);
			divide(len,y-len,len);
			break;
		}
	}
	if(n==-1){cnt=1;return;}
}


int main(){
	cin >> l>>w>>h;
	cin >> N;
	for(int i=0;i<N;i++){
		int kind,num;
		cin>>kind >>num;
		box.push_back(make_pair(kind,num));
	}
	sort(box.begin(),box.end());
	divide(l,w,h);
	if(cnt==0) cout<<use;
	else cout << -1;
	return 0;
}