#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

bool CanGo(string curr, string next, map<string, int>& visited)
{
	if (visited.find(next) != visited.end())
		return false;
	int diff_counter = 0;
	for (int i = 0; i < curr.size(); i++)
	{
		if (curr[i] != next[i])
		{
			if (0 < diff_counter)
			{
				return false;
			}
			diff_counter++;
		}
	}
	return diff_counter == 1;
}

int bfs(string start, string target, vector<string>& graph, map<string,int>& visited)
{
	queue<string> q;
	visited[start] = 0;
	q.push(start);

	string curr;
	while (!q.empty())
	{
		curr = q.front(); q.pop();
		for (string& next : graph)
		{
			if (CanGo(curr, next, visited))
			{
				if (next == target)
				{
					return visited[curr] + 1;
				}
				visited[next] = visited[curr] + 1;
				q.push(next);
			}
		}
	}

	return 0;
}

int solution(string begin, string target, vector<string> words)
{
	map<string, int> visited;

	return bfs(begin, target, words, visited);
}
