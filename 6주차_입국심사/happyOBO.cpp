#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

bool CheckJudgeAll(int n, vector<int>& times, long long total_time)
{
	long long count = 0;
	for (auto it = times.begin(); it != times.end(); it++)
		count += (total_time / static_cast<long long>(*it));
	return n <= count;
}

long long solution(int n, vector<int> times)
{
	int min_time = INT_MAX, max_time = INT_MIN;
	for (auto time : times)
	{
		min_time = min(time, min_time);
		max_time = max(time, max_time);
	}

	long long max_total_time = static_cast<long long>(max_time) * static_cast<long long>(n / times.size());
	long long min_total_time = static_cast<long long>(min_time) * max(static_cast<int>(n / times.size()), 1);
	long long mid_total_time = ( max_total_time + min_total_time ) / 2;
	long long answer = max_total_time;

	while (min_total_time <= max_total_time)
	{
		if (CheckJudgeAll(n, times, mid_total_time))
		{
			answer = min(mid_total_time, answer);
			max_total_time = mid_total_time - 1;
		}
		else
		{
			min_total_time = mid_total_time + 1;
		}
		mid_total_time = (max_total_time + min_total_time) / 2;
	}

	return answer;
}
