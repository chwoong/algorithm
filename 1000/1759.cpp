#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int l,c;
vector<char> pass;
vector<char> ans;
bool isvowel[26]={false,};

void dfs(int current,int num_vowel){
	/* ������ Ž���� �� �߰� ���� l���� �̷���� ������ ��� */
    if(current==c){
		if(ans.size()==l&&num_vowel>=1 && num_vowel<l-1){
			for(int i=0;i<l;i++)
				cout<<ans[i];
			cout<<endl;
		}
		return;
	}
	/*current��°�� ���� ��Ŵ*/
	ans.push_back(pass[current]);
	dfs(current+1,num_vowel+(isvowel[pass[current]-'a']?1:0));
	ans.pop_back();
	/* current��°�� ���� �� ��Ŵ */
	dfs(current+1,num_vowel);
}
 
int main(){
    cin>>l>>c;
	 isvowel[0]=isvowel[4]=isvowel[8]=isvowel[14]=isvowel[20]=true;
	for(int i=0;i<c;i++){
		char x;
		cin>>x;
		pass.push_back(x);
	}
	sort(pass.begin(),pass.end());
	
	dfs(0,0);
	
}