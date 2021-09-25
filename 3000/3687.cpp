#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
using namespace std;
/*성냥개비를 모두 사용해서 만들수 있는 최솟값,최댓값*/
long long mindp[101];

long long solve1(int num){
	if(num==0) return 0;
	if(num<2) return (long long)1<<50;
	long long &ret=mindp[num];
	if(ret!=-1) return ret;
	ret=(long long)1<<52;
	ret=min(ret,10*solve1(num-2)+1);
	ret=min(ret,10*solve1(num-3)+7);
	ret=min(ret,10*solve1(num-4)+4);
	ret=min(ret,10*solve1(num-5)+2);
	ret=min(ret,10*solve1(num-6)+0);
	ret=min(ret,10*solve1(num-7)+8);
	return ret;
}
/*최댓값은 웬만하면 숫자 1과 7만 쓰자*/
string solve2(int num){
	if(num==2) return "1";
	if(num==3) return "7";
	/*4이상의 홀수*/
	if(num%2){
		string ret="7";
		for(int i=1;i<=(num-3)/2;i++){
			ret=ret+"1";
		}
		return ret;
	}else{
		string ret="";
		for(int i=1;i<=num/2;i++){
			ret=ret+"1";
		}
		return ret;
	}
}


int main(){
	int t;
	cin>>t;
	memset(mindp,-1,sizeof(mindp));
	mindp[2]=1; mindp[3]=7; mindp[4]=4; mindp[5]=2; mindp[6]=6;
	mindp[7]=8; mindp[8]=10;
	while(t--){
		int num;
		cin>>num;
		cout<<solve1(num)<<" "<<solve2(num)<<endl;
	}
	return 0;
}