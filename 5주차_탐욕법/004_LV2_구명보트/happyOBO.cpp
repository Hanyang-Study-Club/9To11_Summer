#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

int solution(vector<int> people, int limit)
{
	// sort(people.begin(), people.end());
	priority_queue<int, vector<int>, less<int>> max_heap = priority_queue<int, vector<int>, less<int>>();
	priority_queue<int, vector<int>, greater<int>> min_heap = priority_queue<int, vector<int>, greater<int>>();
	int answer = 0;
	for (int p : people)
	{
		max_heap.push(p);
		min_heap.push(p);
	}

	int people_num = people.size();
	int curr_capacity;
	int counter = 0;
	while (0 < people_num)
	{
		curr_capacity = limit;
		counter = 2;
		while (!max_heap.empty() && max_heap.top() <= curr_capacity && 0 < counter)
		{
			people_num--;
			counter--;
			curr_capacity -= max_heap.top(); max_heap.pop();
		}
		while (!min_heap.empty() && min_heap.top() <= curr_capacity && 0 < counter)
		{
			people_num--;
			counter--;
			curr_capacity -= min_heap.top(); min_heap.pop();
		}
		answer++;
	}

	return answer;
}
