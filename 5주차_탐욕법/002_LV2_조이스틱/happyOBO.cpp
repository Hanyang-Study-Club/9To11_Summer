#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

int min_weight = INT_MAX;
vector<int> directions = { 1, -1 };

void backtrk(vector<bool> visited, int curr, int need_visited_count, int curr_weight)
{
	if (need_visited_count == 0)
	{
		min_weight = min(min_weight, curr_weight);
		return;
	}

	// 전체 탐색 해버림
	if (curr_weight == visited.size() - 1)
	{
		return;
	}

	int next;
	for (int dir : directions)
	{
		next = (curr + dir + visited.size()) % visited.size();

		if (!visited[next])
		{
			visited[next] = true;
			backtrk(visited, next, need_visited_count - 1, curr_weight + 1);
			visited[next] = false;
		}
		else
		{
			backtrk(visited, next, need_visited_count, curr_weight + 1);
		}
	}
}

int solution(string name) {
	int answer = 0;
	vector<bool> visited;
	int need_visited_count = 0;

	// 먼저 상하 움직이는 것 카운트
	for (char c : name)
	{
		if (c == 'A')
		{
			visited.push_back(true);
		}
		else
		{
			visited.push_back(false);
			need_visited_count++;
		}
		answer += min(c - 'A', 'Z' + 1 - c);
	}


	if (visited[0] == false)
	{
		visited[0] = true;
		need_visited_count--;
	}
	backtrk(visited, 0, need_visited_count, 0);

	if (min_weight == INT_MAX) min_weight = 0;

	return min_weight + answer;
}
