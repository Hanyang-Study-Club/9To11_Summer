#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

void backtrk(int& counter, int curr_num , int curr_idx, vector<int>& numbers, int target)
{
	if (curr_idx == numbers.size())
	{
		if (curr_num == target)
		{
			counter++;
		}
		return;
	}
	else
	{
		// + 1
		backtrk(counter, curr_num + numbers[curr_idx], curr_idx + 1, numbers, target);
		// - 1
		backtrk(counter, curr_num - numbers[curr_idx], curr_idx + 1, numbers, target);
	}
}
int solution(vector<int> numbers, int target) {
	int answer = 0;
	backtrk(answer, 0, 0, numbers, target);
	return answer;
}