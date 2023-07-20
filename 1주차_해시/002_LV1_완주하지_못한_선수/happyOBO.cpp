#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	map<string, int> participant_dict;
	for (int i = 0; i < participant.size(); i++)
	{
		if (participant_dict.find(participant[i]) != participant_dict.end())
			participant_dict[participant[i]]++;
		else
			participant_dict.insert(make_pair(participant[i], 1));
	}
	for (int i = 0; i < completion.size(); i++)
	{
		participant_dict[completion[i]]--; // 동명이인 제거
	}

	for (auto iter = participant_dict.begin(); iter != participant_dict.end() ;iter++)
	{
		if (0 < iter->second)
		{
			return iter->first;
		}
	}
	return "";
}