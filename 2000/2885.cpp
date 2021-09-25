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
#include<time.h>
using namespace std;

int k;
int ans;
int n(1);

int main(){
	cin>>k;
	while(n<k) {ans++; n*=2;}
	int i=0;
	while(1){
		if((k & (1<<i))) break;
		i++;
	}
	cout<<n<<' '<<ans-i;
}