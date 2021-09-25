#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    cout << fixed;
    cout.precision(2);
    stack<double>cal;
    char s[101];
    int n;
    double alpha[26];
    cin >> n;
    cin >> s;
    int len = strlen(s);
    for(int i=0;i<26;i++){
        int val;
        cin >> val;
        alpha[i] = val;
    }
    double temp1, temp2;
    for(int i=0;i<len;i++){
        switch(s[i]){
            case '*':
            case '/':
            case '+':
            case '-':
                temp1 = cal.top();
                cal.pop();
                temp2 = cal.top();
                cal.pop();
            if(s[i] == '*') cal.push(temp1*temp2);
            if(s[i] == '/') cal.push(temp2/temp1);
            if(s[i] == '+') cal.push(temp1+temp2);
            if(s[i] == '-') cal.push(temp2-temp1);
            break;
            default: 
            cal.push(alpha[(int)s[i]-65]);
        }
    }
    cout << cal.top();
    return 0;
}