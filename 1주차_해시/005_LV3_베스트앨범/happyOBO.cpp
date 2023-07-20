#include <bits/stdc++.h>
#include <climits>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {

	vector<int> answer;
	map<string, int> genres_acc_dict;
	map<string, pair<int, int>> music_tops;

	for (int i = 0; i < genres.size(); ++i)
	{
		// 1. 누적 플레이수 저장
		if (genres_acc_dict.find(genres[i]) == genres_acc_dict.end())
		{
			genres_acc_dict.insert({ genres[i], plays[i] });
		}
		else
		{
			genres_acc_dict[genres[i]] += plays[i];
		}

		// 2. 장르별 top 2 노래 인덱스 값 저장
		if (music_tops.find(genres[i]) == music_tops.end())
		{
			music_tops.insert({ genres[i], { i, -1 } });
		}
		else
		{
			// 기존의 1등 노래 플레이수 보다 현재 탐색하는 노래의 플레이 수가 더 크다면,
			// 순위 변경
			if (plays[music_tops[genres[i]].first] < plays[i])
			{
				music_tops[genres[i]].second = music_tops[genres[i]].first; // 기존 1등 -> 2등으로 밀려남
				music_tops[genres[i]].first = i;
			}
			// 2 등과 비교 후 순위 변경
			else if (music_tops[genres[i]].second < 0 || plays[music_tops[genres[i]].second] < plays[i])
			{
				music_tops[genres[i]].second = i;
			}
		}
	}

	// 벡터로 정렬
	vector<pair<string, int>> genres_acc_vect(genres_acc_dict.begin(), genres_acc_dict.end());
	sort(genres_acc_vect.begin(), genres_acc_vect.end(), [](pair<string, int> a, pair<string, int> b) { return a.second > b.second; });

	for (pair<string, int>& p : genres_acc_vect)
	{
		answer.push_back(music_tops[p.first].first);
		if (0 <= music_tops[p.first].second)
		{
			answer.push_back(music_tops[p.first].second);
		}
	}
	
	return answer;
}
