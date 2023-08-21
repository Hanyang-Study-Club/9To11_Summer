#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

int getParent(vector<int>& parent, int x);
void unionParent(vector<int>& parent, int a, int b);
bool findParent(vector<int>& parent, int a, int b);

int CalcKruskalAlg(int n, vector<pair<int, pair<int, int>>>& edges)
{
	int weight = 0;
	vector<int> parent(n);

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	sort(edges.begin(), edges.end());

	int edge_counter = 0;
	for (auto& edge : edges)
	{
		if (edge_counter == n - 1)
		{
			break;
		}
		if (!findParent(parent, edge.second.first, edge.second.second))
		{
			unionParent(parent, edge.second.first, edge.second.second);
			edge_counter++;
			weight += edge.first;
		}

	}

	return weight;
}

int getParent(vector<int>& parent, int x)
{
	if (parent[x] == x)
		return x;
	else
		return getParent(parent, parent[x]);
}

// 두 부모를 합치는 함수
void unionParent(vector<int>& parent, int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

// 같은 부모를 가지는지 확인
bool findParent(vector<int>& parent, int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	return a == b;
}

int solution(int n, vector<vector<int>> costs) {
	vector<pair<int, pair<int, int>>> costs_sorted;
	for (auto cost : costs)
	{
		costs_sorted.push_back({ cost[2], { min(cost[0], cost[1]),max(cost[0], cost[1]) } });
	}
	return CalcKruskalAlg(n, costs_sorted);
}