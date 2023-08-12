#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

vector<char> vowels = { 'A', 'E', 'I', 'O', 'U' };
int result = 0;
int counter = 0;

void backtrk(string& target_word, string curr_word)
{
	if (curr_word == target_word)
	{
		result = counter;
		return;
	}
	// 더이상 추가하면 안된다.
	if (curr_word.size() == 5)
	{
		return;
	}
	for (int i = 0; i < vowels.size(); i++)
	{
		counter++;
		backtrk(target_word, curr_word + vowels[i]);
	}
}


int solution(string word) {

	backtrk(word, "");

	return result;
}
