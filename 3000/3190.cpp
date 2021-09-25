#include <iostream>
#include <list>
#include <string>

using namespace std;

int N;

struct Position{
    int row;
    int col;
};

/* game board */
/* »ç°ú ÀÖÀ¸¸é 1 */
/* ¹ì ÀÖÀ¸¸é 2 */
/* ¾øÀ¸¸é 0 */
int arr[102][102]={0};

list <Position> snake;

int move_row[4] = {0,1,0,-1};
int move_col[4] = {1,0,-1,0};

bool isend(){
    if(snake.back().row ==0 || snake.back().row ==N+1) return true;
    if(snake.back().col ==0 || snake.back().col ==N+1) return true;
    return false;
}

int main()
{
    int apple_num;
    cin >> N;
    
    /* set apples in board */
    cin >> apple_num;
    for(int i=0;i<apple_num;i++){
        int row,col;
        cin >> row >> col;
        arr[row][col] = 1;
    }
    Position pos;
    
    pos.row=1;
    pos.col=1;
    snake.push_back(pos);
    arr[pos.row][pos.col]=2;
    
    /* game time*/
    int past_time=0;
    int direct_num;
    cin >> direct_num;
    int m=0;
    
    int times[100];
    char direct[100];
    for(int i=0;i<direct_num;i++){
        cin >> times[i] >> direct[i];
    }
    int end=0;
    for(int i=0;i<direct_num;i++){
        while(past_time != times[i]){
            pos.row = snake.back().row + move_row[m];
            pos.col = snake.back().col + move_col[m];
            /* ¹ì ¸öÅëÀÌ ´Ù °°ÀÌ ÇÑÄ­ ÀüÁø */
            if(arr[pos.row][pos.col] == 0){
                arr[snake.front().row][snake.front().col]=0;
                snake.push_back(pos);
                arr[pos.row][pos.col] =2;
                snake.pop_front();
            }
            /* »ç°ú ¸¸³ª¸é ¹ì ¸öÅëÀÌ ±æ¾îÁü */
            else if(arr[pos.row][pos.col] == 1){
                snake.push_back(pos);
                arr[pos.row][pos.col] =2;
            }
            /* ¿òÁ÷¿´´Âµ¥ ¸öÅë ¸¸³ª¸é °× ³¡ */
            else {cout << past_time+1<<endl; end=1; i=direct_num; break;}
            past_time++;
            if(isend()) {cout << past_time<<endl; end=1;i=direct_num; break;}
        }
        /* ¹æÇâ ¹Ù²ãÁÜ */
        direct[i] == 'L'? m=(4+m-1)%4 : m=(m+1)%4;
        //cout << past_time<<"M" <<m <<endl;
    }
    
    while(end==0){
        pos.row = snake.back().row + move_row[m];
            pos.col = snake.back().col + move_col[m];
            // ¹ì ¸öÅëÀÌ ´Ù °°ÀÌ ÇÑÄ­ ÀüÁø 
            if(arr[pos.row][pos.col] == 0){
                arr[snake.front().row][snake.front().col]=0;
                snake.push_back(pos);
                arr[pos.row][pos.col] =2;
            }
            // »ç°ú ¸¸³ª¸é ¹ì ¸öÅëÀÌ ±æ¾îÁü
            else if(arr[pos.row][pos.col] == 1){
                snake.push_back(pos);
                arr[pos.row][pos.col] =2;
            }
            // ¿òÁ÷¿´´Âµ¥ ¸öÅë ¸¸³ª¸é °× ³¡ 
            else {cout << past_time+1; break;}
            past_time++;
            if(isend()) {cout << past_time; break;}
    }
    
    return 0;
}