#include <iostream> 

using namespace std; 

/* maximum number of consecutive candies */
int maxi=0;
int N;
/* get maxi function*/
void getnum(char **arr){
    for(int i=0;i<N;i++){
        int tmp=1;
        for(int j=0;j<N-1;j++){
            if(arr[i][j]==arr[i][j+1]){
                tmp++;
                if(maxi < tmp) maxi = tmp;
            }else{
                tmp=1;
            }
        }
    }
    for(int j=0;j<N;j++){
        int tmp=1;
        for(int i=0;i<N-1;i++){
            if(arr[i][j]==arr[i+1][j]){
                tmp++;
                if(maxi < tmp) maxi = tmp;
            }else{
                tmp=1;
            }
        }
    }
}

int main() 
{ 
    cin >> N;
    char **arr = new char *[N];
    for(int i=0;i<N;i++){
        arr[i] = new char[N];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            /* exchange two candies */
            char temp = arr[i][j+1];
            arr[i][j+1] = arr[i][j];
            arr[i][j] =temp;
            getnum(arr);
            /* reinstatement */
            temp = arr[i][j+1];
            arr[i][j+1] = arr[i][j];
            arr[i][j] =temp;
        }
    }
    for(int j=0;j<N;j++){
        for(int i=0;i<N-1;i++){
            /* exchange two candies */
            char temp = arr[i+1][j];
            arr[i+1][j] = arr[i][j];
            arr[i][j] =temp;
            getnum(arr);
            /* reinstatement */
            temp = arr[i+1][j];
            arr[i+1][j] = arr[i][j];
            arr[i][j] =temp;
        }
    }
    
    cout << maxi;
    
    for(int i=0;i<N;i++){
       delete[] arr[i];
    }
    delete []arr;
    return 0;
}