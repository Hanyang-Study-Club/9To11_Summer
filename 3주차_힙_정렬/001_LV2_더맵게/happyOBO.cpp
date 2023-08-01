#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    
    int answer = 0;
    
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int sc : scoville)
	{
		pq.push(sc);
	}
    
    int top1, top2, curr_scoville;
    while(!pq.empty() && pq.top() < K && 2 <= pq.size() )
    {
        answer++;
        top1 = pq.top(); pq.pop();
        top2 = pq.top(); pq.pop();
        curr_scoville = top1 + top2 * 2;
        pq.push(curr_scoville);
    }
    
    if(pq.top() < K || pq.empty())
    {
        return -1;
    }
    return answer;
}