#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

int CheckDeleteRocks(int distance, int min_dist, vector<int>& rocks)
{
	int deleted_rocks = 0;
	int curr_pos = 0;
	int curr_dist = 0;
	for (int& rock : rocks)
	{
		if (min_dist <= rock - curr_pos)
		{
			curr_pos = rock;
		}
		else
		{
			deleted_rocks++;
		}
	}
    // 마지막 바위 ~ 거리 끝 체크
	if (distance - curr_pos < min_dist)
	{
		return deleted_rocks + 1;
	}
	return deleted_rocks;
}

int solution(int distance, vector<int> rocks, int n)
{
	int max_distance = distance;
	int min_distance = 0;
	int mid = (max_distance + min_distance) / 2;
	int answer = min_distance;

	sort(rocks.begin(), rocks.end());
	while (min_distance <= max_distance)
	{
		if (CheckDeleteRocks(distance, mid, rocks) <= n)
		{
			min_distance = mid + 1;
			answer = max(answer, mid);
		}
		else
		{
			max_distance = mid - 1;
		}
		mid = (max_distance + min_distance) / 2;
	}

	return answer;
}