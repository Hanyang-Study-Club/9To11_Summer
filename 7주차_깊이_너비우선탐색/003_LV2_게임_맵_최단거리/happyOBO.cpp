#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

bool CanGo(pair<int, int>& pos, vector<vector<int>>& graph, vector<vector<int>>& distance);

vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void bfs(pair<int,int> start, vector<vector<int>>& graph, vector<vector<int>>& distance)
{
	queue<pair<int,int>> q;
	distance[start.first][start.second] = 1;
	q.push(start);

	pair<int,int> curr, next;
	while (!q.empty())
	{
		curr = q.front(); q.pop();

		for (pair<int,int>& dir : directions)
		{
			next = { curr.first + dir.first , curr.second + dir.second };
			if (CanGo(next, graph, distance))
			{
				q.push(next);
				distance[next.first][next.second] = distance[curr.first][curr.second] + 1;
			}
		}
	}
}

bool CanGo(pair<int, int>& pos, vector<vector<int>>& graph, vector<vector<int>>& distance)
{
	if (graph.size() <= pos.first || pos.first < 0)
	{
		return false;
	}
	if (graph[0].size() <= pos.second || pos.second < 0)
	{
		return false;
	}
	
	return graph[pos.first][pos.second] == 1 && distance[pos.first][pos.second] < 0;
}

int solution(vector<vector<int> > maps)
{
	int answer = 0;
	vector<vector<int>> distance = vector<vector<int>>(maps.size(), vector<int>(maps[0].size(), -1));
	bfs({ 0,0 }, maps, distance);
	if (distance[maps.size() - 1][maps[0].size() - 1] < 0)
	{
		return -1;
	}

	return distance[maps.size() - 1][maps[0].size() - 1];
}