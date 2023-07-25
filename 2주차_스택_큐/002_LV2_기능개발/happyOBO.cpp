#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    stack<int> s;
    int remain_work_days;
    vector<int> answer;
    
    for(int i = 0; i < progresses.size(); ++i)
    {
        remain_work_days = (100 - progresses[i]) % speeds[i] == 0 ? (100 - progresses[i]) / speeds[i] : (100 - progresses[i]) / speeds[i] + 1;
        if(s.empty() || s.top() < remain_work_days)
        {
            s.push(remain_work_days);
            answer.push_back(1);
        }
        else
        {
            answer[answer.size() - 1]++;
        }
    }
    
    return answer;
}