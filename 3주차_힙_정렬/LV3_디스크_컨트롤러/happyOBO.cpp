#include <bits/stdc++.h>
#include <climits>

using namespace std;

int solution(vector<vector<int>> jobs) {

	vector<pair<int, int>> sorted_job;

	for (vector<int>& job : jobs)
	{
		sorted_job.push_back({ job[0], job[1] });
	}

	pair<int, int> current_job;
	int current_time = 0, answer = 0, job_count = sorted_job.size();
	while (!sorted_job.empty())
	{
		// pop_back 할거므로 우선순위가 높은게 끝에 오도록
		sort(sorted_job.begin(), sorted_job.end(),
			[&current_time](pair<int, int> a, pair<int, int> b)
			{
				// 이미 현재 시간 상 a ,b 가 대기 하지 않아도 되는 경우
				if (current_time >= a.first && current_time >= b.first || (a.first == b.first))
				{
					// 작업량이 적은 게 우선 순위가 더 높다.
					return a.second > b.second;
				}
				else
				{
					// 빨리 시작하는게 우선 순위가 더 높다.
					return a.first > b.first;
				}
			});
		current_job = sorted_job[sorted_job.size() - 1]; sorted_job.pop_back();
		
		// 현재 시간 보다 작업 가능 시점이 더 큰 경우 update
		if (current_time < current_job.first)
		{
			current_time = current_job.first;
		}
		else
		{
			// 요청 후 부터 대기 시간
			answer += (current_time - current_job.first);
		}
		// 작업 시간
		answer += current_job.second;
		current_time += current_job.second;
	}

	if (job_count == 0)
		return 0;
	else
		return answer / job_count;
}