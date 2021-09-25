#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<string.h>
#include<set>
#include<stdlib.h>
using namespace std;

typedef pair<int,int> P;
int n,m;
vector<P> x,y;
long long ansx;
long long ansy;
int a,b;
int main(){
	int myints[] = {10,20,30,30,20,10,10,20};
 	vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20
	sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30
	vector<int>::iterator low,up;
	low=std::lower_bound (v.begin(), v.end(), 20); //          ^
	up= std::upper_bound (v.begin(), v.end(), 20); //
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x1,y1;
		scanf("%d %d",&x1,&y1);
		x.push_back(P(x1,0));
		y.push_back(P(y1,0));
		ansx+=abs(x1);
		ansy+=abs(y1);
	}
	x.push_back(P(10000000,n));
	y.push_back(P(10000000,n));
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	for(int i=0;i<n;i++){
		x[i].second=i;
		y[i].second=i;
	}
	string s;
	cin>>s;
	int p,q;
	for(int i=0;i<m;i++){
		switch(s[i]){
			case 'S':
				b++;
				p=(*lower_bound(y.begin(),y.end(),P(b,0))).second;
				q=n-p;
				ansy+=(p-q);
				break;
			case 'J':
				b--;
				p=(*upper_bound(y.begin(),y.end(),P(b,n))).second;
				q=n-p;
				ansy+=(q-p);
				break;
			case 'I':
				a++;
				p=(*lower_bound(x.begin(),x.end(),P(a,0))).second;
				q=n-p;
				ansx+=(p-q);
				break;
			case 'Z':
				a--;
				p=(*upper_bound(x.begin(),x.end(),P(a,n))).second;
				q=n-p;
				ansx+=(q-p);
				break;
		}
		//cout<<b<<" "<<p<<" "<<q<<endl;
		printf("%lld\n",ansx+ansy);
	}
	return 0;
}