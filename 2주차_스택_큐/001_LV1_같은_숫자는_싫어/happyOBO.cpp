#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr)
{
    stack<int> s;
    vector<int> answer;
    
    for(int e : arr)
    {
        if(s.empty() || s.top() != e)
        {
            s.push(e);
            answer.push_back(e);
        }
    }

    return answer;
}