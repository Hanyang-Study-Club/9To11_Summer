#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

const int BOUND = 50 * 50;

// 겹쳐진 직사각형 인덱스 누적
set<int> graph[50][50] = {};
int dist[50][50] = {};

int bfs(int start, int end, vector<vector<int>>& v_graph)
{
	vector<int> dist= vector<int>(v_graph.size(),-1);
	queue<int> q;
	dist[start] = 0;
	q.push(start);

	int curr;
	while (!q.empty())
	{
		curr = q.front(); q.pop();
		for (int next : v_graph[curr])
		{
			if (dist[next] < 0)
			{
				dist[next] = dist[curr] + 1;
				q.push(next);
			}
		}
	}

	return dist[end];
}

bool CheckDuplication(set<int>& s1, set<int>& s2)
{
	int counter = 0;
	if (s1.size() == 0 && s2.size() == 0)
	{
		return false;
	}
	for (int e1 : s1)
	{
		if (s2.find(e1) != s2.end())
		{
			counter++;
		}
	}
	return counter == 1;
}

void AddGraphNode(pair<int, int> curr, pair<int, int> next, vector<vector<int>>& v_graph)
{
	if (curr.first * 50 + curr.second < BOUND && next.first * 50 + next.second < BOUND 
		&& CheckDuplication(graph[curr.first][curr.second], graph[next.first][next.second]))
	{
		v_graph[curr.first * 50 + curr.second].push_back(next.first * 50 + next.second);
		v_graph[next.first * 50 + next.second].push_back(curr.first * 50 + curr.second);
	}
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
	// idx = y * 50 + x
	vector <vector<int>> v_graph(BOUND);

	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++)
			dist[i][j] = -1;


	int lx, ly, rx, ry;
	for (int rect_idx = 0; rect_idx < rectangle.size(); rect_idx++)
	{
		lx = rectangle[rect_idx][0] - 1;
		ly = rectangle[rect_idx][1] - 1;
		rx = rectangle[rect_idx][2] - 1;
		ry = rectangle[rect_idx][3] - 1;

		for (int y = ly; y <= ry; y++)
		{
			for (int x = lx; x <= rx; x++)
			{
				graph[y][x].insert(rect_idx);
			}
		}
	}

	for (vector<int>& rec : rectangle)
	{
		lx = rec[0] - 1;
		ly = rec[1] - 1;
		rx = rec[2] - 1;
		ry = rec[3] - 1;

		for (int y = ly; y <= ry; y++)
		{
			if (y + 1 <= ry)
			{
				AddGraphNode({ y, lx }, { y + 1,lx }, v_graph);
				AddGraphNode({ y, rx }, { y + 1,rx }, v_graph);
			}

		}
		for (int x = lx; x <= rx; x++)
		{
			if (x + 1 <= rx)
			{
				AddGraphNode({ ly, x }, { ly, x + 1 }, v_graph);
				AddGraphNode({ ry, x }, { ry, x + 1 }, v_graph);
			}

		}
	}

	return bfs((characterY - 1) * 50 + characterX - 1 , (itemY - 1) * 50 + itemX - 1, v_graph);
}
