#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    list<char> word;
    list<char> pass;
    
    list<char>::iterator it;
    list<char>::iterator jt=pass.begin();
    
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++){
             word.push_back(s[j]);
        }
    jt=pass.begin();
    for(it=word.begin();it!=word.end();it++){
        char input= *it;
        switch(input){
            case '<':
                if(jt!=pass.begin()) jt--;
                break;
            case '>':
                if(jt!=pass.end()) jt++;
                break;
            case '-':
               if(jt!=pass.begin()){
                    jt--;
                    jt=pass.erase(jt);
                }
                break;
            default:
                jt=pass.insert(jt,input);
                if(jt!=pass.end()) jt++;
                break;
        }
    }
    for(it = pass.begin(); it!=pass.end();it++){
        cout << *it;
    }
    word.clear();
    pass.clear();
    if(i!=N-1) cout << endl;
    }
    
    return 0;
}