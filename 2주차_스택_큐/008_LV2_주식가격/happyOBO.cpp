#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	
	vector<int> answer;
	
	int counter = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		counter = 0;
		for (int j = i + 1; j < prices.size(); j++)
		{
			counter++;
			if (prices[j] < prices[i])
			{
				break;
			}
		}

		answer.push_back(counter);
	}
	
	return answer;
}