#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited)
{
	queue<int> q;
	visited[start] = true;
	q.push(start);
	
	int curr;
	while (!q.empty())
	{
		curr = q.front(); q.pop();
		for (int next : graph[curr])
		{
			if (!visited[next])
			{
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int solution(int n, vector<vector<int>> computers)
{
	vector<vector<int>> graph(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j && computers[i][j] == 1)
			{
				graph[i].push_back(j);
			}
		}
	}

	int answer = 0;
	vector<bool> visted(n, false);

	for (int i = 0; i < n; i++)
	{
		if (!visted[i])
		{
			answer++;
			bfs(i, graph, visted);
		}
	}

	return answer;
}
