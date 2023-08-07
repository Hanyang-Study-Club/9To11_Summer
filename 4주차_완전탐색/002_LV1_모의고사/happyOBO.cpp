#include <string>
#include <vector>

using namespace std;

int first_per(vector<int> answers)
{
    vector<int> pattern = {1, 2, 3, 4, 5};
    int idx = 0, corrects = 0;
    int mod = pattern.size();
    while (true)
    {
        if(answers.size() <= idx) return corrects;
        if(answers[idx] == pattern[idx % mod]) corrects++;
        idx++;
    }
}

int second_per(vector<int> answers)
{
    vector<int> pattern = {2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5};
    int idx = 0, corrects = 0;
    int mod = pattern.size();
    while (true)
    {
        if(answers.size() <= idx) return corrects;
        if(answers[idx] == pattern[idx % mod]) corrects++;
        idx++;
    }
}

int third_per(vector<int> answers)
{
    vector<int> pattern = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int idx = 0, corrects = 0;
    int mod = pattern.size();
    while (true)
    {
        if(answers.size() <= idx) return corrects;
        if(answers[idx] == pattern[idx % mod]) corrects++;
        idx++;
    }
}

vector<int> ret_max(vector<int> sc)
{
    int mx = 0;
    vector<int> answer;
    for(int i = 0; i<sc.size(); i++)
    {
        if(mx < sc[i])
        {
            mx = sc[i];
            answer.clear();
            answer.push_back(i+1);
        }
        else if(mx == sc[i])
        {
            answer.push_back(i+1);
        }

    }
    return answer;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> scores = {first_per(answers), second_per(answers), third_per(answers)};
    return ret_max(scores);
}