#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

int solution(vector<int> citations) {

	sort(citations.begin(), citations.end());

	int answer = 0, citations_size = citations.size(), remained_count = 0;
	for (int h = citations_size; 0 <= h; h--)
	{
		if ( citations[citations_size - h] >= h)
		{
			return h;
		}
	}

	return answer;
}
