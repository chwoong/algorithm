#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string word;
    for(int i=0;i<N;i++){
        cin >> word;
        if(word[word.size()-1]%2) cout << "odd" <<endl;
        else cout << "even" << endl;
    }
    return 0;
}