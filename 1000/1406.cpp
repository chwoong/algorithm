#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    list<char> word;
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        word.push_back(s[i]);
    }
    list<char>::iterator it=word.end();
    
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        char input;
        cin >> input;
        switch(input){
            case 'P':
                cin >> input;
                it=word.insert(it,input);
                it++;
                break;
            case 'L':
                //cout << "L"; 
                if(it!=word.begin()) it--;
                break;
            case 'D':
                if(it!=word.end()) it++;
                break;
            case 'B':
                if(it!=word.begin()){
                    it--;
                    it=word.erase(it);
                }
                break;
        }
    }
    
    for(it = word.begin(); it!=word.end();it++){
        cout << *it;
    }
    return 0;
}