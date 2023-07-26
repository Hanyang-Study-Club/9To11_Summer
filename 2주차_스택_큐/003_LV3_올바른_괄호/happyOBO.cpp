#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int counter = 0;
    
    for(char c : s)
    {
        if(c == '(')
        {
            counter++;
        }
        else if(0 < counter)
        {
            counter--;
        }
        else
        {
            answer = false;
            break;
        }
    }
    
    // counter 가 남아 있다면 ( 가 닫히지 않고 끝난 경우므로 false 리턴
    return !answer ? false : counter == 0;
}