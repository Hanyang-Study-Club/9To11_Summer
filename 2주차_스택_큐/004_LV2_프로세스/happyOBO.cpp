#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int solution(vector<int> priorities, int location) {
	map<int, int> p_frequency;
	queue<pair<int, int>> q;
	for (int i = 0; i < priorities.size(); i++)
	{
		if (p_frequency.find(priorities[i]) != p_frequency.end())
		{
			p_frequency[priorities[i]]++;
		}
		else
		{
			p_frequency.insert({ priorities[i], 1 });
		}
		q.push({ priorities[i],i });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>> > pq;
	for (pair<int, int> p_f : p_frequency)
	{
		pq.push(p_f);
	}

	int order = 1;
	pair<int, int> top, curr;
	while (!q.empty())
	{
		// first : 현재 탐색하고 있는 큐 원소의 우선순위 값
		// second : 현재 탐색하고 있는 큐 원소의 원래 위치 값
		curr = q.front();

		// q 에 남아있는 원소 중 가장 우선 순위가 큰 값과 개수
		top = pq.top();

		q.pop();
		
		if (curr.first < top.first) // 더 큰 우선 순위 값이 남아있어서 실행 불가
		{
			// 다시 넣어준다.
			q.push(curr);
		}
		else // 프로세스 실행 가능
		{
			if (curr.second == location)
				return order;
			order++;
			pq.pop();
			// 개수를 변경 해주고 다시 push.
			top.second--;
			if (0 < top.second)
			{
				pq.push(top);
			}
		}
	}
	return -1;
}