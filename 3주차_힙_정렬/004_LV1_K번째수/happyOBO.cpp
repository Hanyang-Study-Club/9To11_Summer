#include <bits/stdc++.h>
#include <climits>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (vector<int>& command : commands)
	{
		vector<int> sub_arr(array.begin() + command[0] - 1, array.begin() + command[1]);
		sort(sub_arr.begin(), sub_arr.end());
		answer.push_back(sub_arr[command[2] - 1]);
	}
	return answer;
}
