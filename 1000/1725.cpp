#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

/* arr[i] ~ arr[j]까지 중 최대 넓이 반환  */
int maxValue(int i,int j){
    if(i==j) return arr[i];
    int ret=0;
    int mid =(i+j)/2;
    ret = max(maxValue(i,mid), maxValue(mid+1,j));
    int left(mid), right(mid+1);
    int height = min(arr[left],arr[right]);
    ret=max(ret, height * (right-left+1) );
    while(left != i || right != j){
        if(right +1 <=j && left-1 >=i){
            if(arr[right+1]>arr[left-1]) height=min(height,arr[++right]);
            else height=min(height,arr[--left]);
        }
        else if(right +1 <=j) height=min(height,arr[++right]);
        else height=min(height,arr[--left]);
        
        ret=max(ret, height * (right-left+1) );
    }
    return ret;
}

int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    
    cout << maxValue(0,N-1);
    return 0;
}