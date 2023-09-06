#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

int max_count;
vector<string> result;

void dfs(string curr, map<string, vector<string>>& graph, map<string, vector<bool>> visited, vector<string> result_temp)
{
	if (result_temp.size() == max_count)
	{
		if (result.size() == 0)
		{
			result = result_temp;
		}
		else
		{
			for (int i = 0; i < max_count; i++)
			{
				if (result_temp[i] < result[i])
				{
					result = result_temp;
					return;
				}
				else if (result_temp[i] > result[i])
				{
					return;
				}
			}
		}
		return;
	}

	for (int i = 0; i < graph[curr].size(); i++)
	{
		if (visited[curr][i] == false)
		{
			visited[curr][i] = true;
			result_temp.push_back(graph[curr][i]);
			dfs(graph[curr][i], graph, visited, result_temp);
			visited[curr][i] = false;
			result_temp.pop_back();
		}
	}
}

vector<string> solution(vector<vector<string>> tickets)
{
	map<string, vector<string>> graph;
	map<string, vector<bool>> visited;
	for (int i = 0; i < tickets.size(); i++)
	{
		if (graph.find(tickets[i][0]) == graph.end())
		{
			graph.insert({ tickets[i][0],{tickets[i][1]}});
			visited.insert({ tickets[i][0],{false} });
		}
		else
		{
			graph[tickets[i][0]].push_back(tickets[i][1]);
			visited[tickets[i][0]].push_back(false);
		}
	}

	max_count = tickets.size() + 1;
	dfs("ICN", graph, visited, { "ICN" });
	return result;
}