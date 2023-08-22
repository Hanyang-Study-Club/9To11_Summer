#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;


int solution(vector<vector<int>> routes)
{
	vector<pair<int, int>> v;
	for (vector<int>& route : routes)
	{
		v.push_back({ route[0], route[1] });
	}

	// 나가는게 빠른 순서대로 정렬
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
	int answer = 1;
	int camera = v[0].second;

	for (int i = 1; i < v.size(); i++)
	{
		// 겹치지 않는다.
		if (camera < v[i].first)
		{
			answer++;
			camera = v[i].second;
		}
		// 겹칠 때는 카메라 위치 안바꿔도 된다.
	}
	return answer;
}
