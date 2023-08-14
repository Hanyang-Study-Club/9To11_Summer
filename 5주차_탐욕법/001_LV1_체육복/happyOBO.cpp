#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if (lost[i] == reserve[j])
			{
				lost.erase(lost.begin() + i);
				reserve.erase(reserve.begin() + j);
				i = -1;
				break;
			}
		}
	}

	

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	int counter = n - lost.size();

	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if (lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j])
			{
				counter++;
				reserve.erase(reserve.begin() + j);
				break;
			}
		}
	}

	return counter;
}
