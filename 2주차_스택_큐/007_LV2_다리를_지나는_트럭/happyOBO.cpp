#include <string>
#include <vector>
#include <queue>

using namespace std;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int capacity_weight = 0;
	queue<pair<int,int>> q;
	
	// value, 개수
	q.push({0,bridge_length});

	pair<int, int> curr;
	for (int w : truck_weights)
	{
		if (weight < capacity_weight + w)
		{
			while (true)
			{
				curr = q.front();
				answer += curr.second; // 개수만큼 시간을 더한다.
				capacity_weight -= curr.first;

				q.pop();
				if (capacity_weight + w <= weight)
				{
					q.push({ w, 1 });
					break;
				}
				else
				{
					q.push({0, curr.second});
				}
			}
		}
		else
		{
			capacity_weight -= q.front().first;
			answer++;

			if (1 < q.front().second)
			{
				q.front().second--;
			}
			else
			{
				q.pop();
			}

			q.push({w, 1});
		}
		capacity_weight += w;
	}

	while (0 < capacity_weight && !q.empty())
	{
		capacity_weight -= q.front().first;
		answer += q.front().second;
		q.pop();
	}
	return answer;
}

