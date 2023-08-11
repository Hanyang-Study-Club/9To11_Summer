#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;


int bfs(int start, int n, vector<vector<int>>& wires_graph, pair<int, int> banned)
{
	vector<bool> visited = vector<bool>(n, false);
	queue<int> q;
	visited[start] = true;
	q.push(start);
	int curr, counter = 1;
	while (!q.empty())
	{
		curr = q.front(); q.pop();
		for (int next : wires_graph[curr])
		{
			if (!visited[next] &&
				// 자른 구간으로 넘어가 버리면 안된다.
				! ( banned.first == curr && banned.second == next ) &&
				! ( banned.first == next && banned.second == curr ))
			{
				visited[next] = true;
				counter++;
				q.push(next);
			}
		} 
	}
	return counter;
}

int solution(int n, vector<vector<int>> wires) {

	vector<vector<int>> wires_graph = vector<vector<int>>(n);

	for (int i = 0; i < wires.size(); i++)
	{
		// 인덱싱으로 변경 1 ~ N --> 0 ~ N-1
		wires[i][0]--; wires[i][1]--;
		wires_graph[wires[i][0]].push_back(wires[i][1]);
		wires_graph[wires[i][1]].push_back(wires[i][0]);
	}

	int wire_count, min_diff = INT_MAX;

	// bfs
	for (int i = 0; i < wires.size(); i++)
	{
		// wires[i][0] --> wires[i][1] 로 가는게 끊겨 버렸으니
		// wires[i][1] 에서 start
		wire_count = bfs(wires[i][1], n, wires_graph, { wires[i][0] , wires[i][1] });
		min_diff = min(min_diff, abs(n - wire_count - wire_count ));
	}
	return min_diff;
}