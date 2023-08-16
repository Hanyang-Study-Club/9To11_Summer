#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

string solution(string number, int k)
{
	list<char> li;
	for (char c : number)
	{
		li.push_back(c);
	}

	bool berase = false;
	for (int i = 0; i < k; i++)
	{
		berase = false;
		list<char>::iterator prev_it = li.begin();
		for (list<char>::iterator it = li.begin(); it != li.end(); ++it)
		{
			if (it == li.begin()) continue;
			else
			{
				if (*it > *prev_it)
				{
					li.erase(prev_it);
					berase = true;
					break;
				}
				prev_it = it;
			}
		}
		if (!berase)
		{
			li.erase(prev_it);
		}
	}

	string answer = "";
	while (!li.empty())
	{
		answer += li.front();  li.pop_front();
	}
	
	return answer;
}
