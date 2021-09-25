/*
 *  author: chw0501
 *  reference: 
 *  created: 30.09.2020 10:35:38(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 


int n;
int inord[100000];
int postord[100000];
int ind[100001];


void solve(int i, int j, int length){
    int root = postord[j+length];
    if(length<0) return;    
    printf("%d ",root);
    if(length==0) return;
    int val =ind[root];
    solve(i, j, val-i-1);
    solve(val+1, j+val-i, length-val+i-1);
}

int main(){
	scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",inord+i);
        ind[inord[i]]=i;
    }
    for(int i=0;i<n;i++){
        scanf("%d",postord+i);
    }
    solve(0, 0, n-1);
	return 0;
}