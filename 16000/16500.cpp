#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int N;
char arr[101]={0};
vector <string> words;
int dp[101];
int Size;

/* arr[n]~ arr[Size-1] 까지 만드는 것이 가능하면 return 1 */
int isPossible(int n){
    if(n==Size) return 1;
    int &ret = dp[n];
    if(ret != -1) return ret;
    
    ret =0;
    /* arr[n]부터 확인했을 때 채울 수 없는 것의 개수 */
    int judge=0;
    for(int i=0;i<N;i++){
        int temp=1;
        for(int j=0;j<words[i].size() ;j++){
            if(arr[n+j] != words[i][j]){
                judge++;
                temp =0;
                break;
            }
        }
        if(temp == 1){
            ret =  ret || isPossible(n+words[i].size());
        }
        
    }
    if(judge == N) ret = 0;
    return ret;
}

int main(){
    string word;
    cin >> arr;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> word;
        words.push_back(word);
    }
    int x=0;
    while(arr[x]!=0){
        x++;
    }
    Size=x;
    /* set dp array's elements to -1*/
    memset(dp,-1,sizeof(dp));
    
    /* judgement */
    cout << isPossible(0);
    return 0;
}