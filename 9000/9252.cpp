#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

/*lcs[i][j]:
첫번째 문자열의 1...i까지의 sustring과
두번째 문자열의 1...j까지의 substring에서
longest common subsequence의 길이
*/
int lcs[1010][1010]={0,};

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int len1=s1.size();
	int len2=s2.size();
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			if(s1[i-1]==s2[j-1]) lcs[i][j]=lcs[i-1][j-1]+1;
			else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
		}
	}
	cout<<lcs[len1][len2]<<endl;
	int tmp=lcs[len1][len2];
	vector<char> v;
	int jcurr=len2;
	for(int i=len1;i>=1;i--){
		for(int j=jcurr;j>=1;j--){
			if(lcs[i][j]==tmp && lcs[i-1][j-1]==tmp-1 && s1[i-1]==s2[j-1]){
				v.push_back(s1[i-1]);
				jcurr=j-1;
				tmp--;
				break;
			}
		}
	}
	for(int i=lcs[len1][len2]-1;i>=0;i--){
		cout<<v[i];
	}
	return 0;
}