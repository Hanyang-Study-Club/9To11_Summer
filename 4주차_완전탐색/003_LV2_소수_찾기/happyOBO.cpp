#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

bool CheckUniquePrime(string str_num);

vector<bool> visited;
set<int> prime_dict;

void backtrk(string numbers, string curr_num, int& counter)
{
	if (CheckUniquePrime(curr_num))
	{
		counter++;
	}

	for (int i = 0; i < visited.size(); i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			backtrk(numbers, curr_num + numbers[i], counter);
			visited[i] = false;
		}
	}
}

bool CheckUniquePrime(string str_num)
{
	if (str_num.size() <= 0) return false;
	
	int num = stoi(str_num);
	if (num <= 1) return false;
	if (prime_dict.find(num) != prime_dict.end()) return false;
	for (int i = 2; i < num / 2 + 1; i++)
	{
		if (num % i == 0)
			return false;
	}

	prime_dict.insert(num);
	return true;
}

int solution(string numbers) {

	for (int i = 0; i < numbers.size(); i++)
		visited.push_back(false);
	int answer = 0;
	backtrk(numbers, "", answer);
	return answer;
}