#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    stack<char>cal;
    char s[101];
 
    cin >> s;
    int len = strlen(s);
    
    for(int i=0;i<len;i++){
        switch(s[i]){
            case '*':
            case '/':
                while(!cal.empty()){
                    if(cal.top()=='(' || cal.top()=='+' || cal.top()=='-') break;
                    cout << cal.top();
                    cal.pop();
                }
            case '(':
                cal.push(s[i]);
                break;
            case '+':
            case '-':
                while(!cal.empty()){
                    if(cal.top()=='(') break;
                    cout << cal.top();
                    cal.pop();
                }
                cal.push(s[i]);
                break;
            case ')':
                while(cal.top()!='('){
                    cout << cal.top();
                    cal.pop();
                }
                cal.pop();
                break;
            default: cout << s[i];
        }
    }
    
    while(!cal.empty()){
        cout << cal.top();
        cal.pop();
    }
    return 0;
}