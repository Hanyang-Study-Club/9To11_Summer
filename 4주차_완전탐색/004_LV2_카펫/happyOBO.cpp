#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	int x_out, y_out, x_in, y_in;

	for (int x_out = 1; x_out < brown; x_out++)
	{
		y_out = ( brown - 2 * x_out ) / 2 + 2;
		if (y_out <= 0)
		{
			break;
		}
		if ((x_out - 2) * (y_out - 2) == yellow)
		{
			return { y_out, x_out };
		}
	}
	return answer;
}
