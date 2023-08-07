#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

int solution(vector<vector<int>> sizes) {

	int x_max = INT_MIN, y_max = INT_MIN;
	for (auto& card_size : sizes)
	{
		x_max = max(x_max, max(card_size[0], card_size[1]));
		y_max = max(y_max, min(card_size[0], card_size[1]));
	}

	return x_max * y_max;
}
