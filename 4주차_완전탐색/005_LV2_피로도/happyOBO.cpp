#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;
bool CanVisitDungeon(int curr_k, int dungeon_idx, vector<vector<int>>& dungeons);

vector<bool> visited;
int max_counter = INT_MIN;

void backtrk(int counter, int curr_k, vector<vector<int>>& dungeons)
{
	if (max_counter < counter)
	{
		max_counter = counter;
	}

	for(int i = 0; i < dungeons.size(); i++)
	{
		if (CanVisitDungeon(curr_k, i, dungeons))
		{
			visited[i] = true;
			backtrk(counter + 1, curr_k - dungeons[i][1], dungeons);
			visited[i] = false;
		}
	}
}

bool CanVisitDungeon(int curr_k, int dungeon_idx, vector<vector<int>>& dungeons)
{
	if (visited[dungeon_idx] == false)
	{
		return dungeons[dungeon_idx][0] <= curr_k;
	}
	return false;
}

int solution(int k, vector<vector<int>> dungeons) {

	visited.resize(dungeons.size(), false);
	backtrk(0, k, dungeons);
	return max_counter;
}