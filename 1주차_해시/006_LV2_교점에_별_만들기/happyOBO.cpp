#include <bits/stdc++.h>
#include <climits>

using namespace std;

struct Line
{
	long long A;
	long long B;
	long long C;
};

struct Dot
{
	long long Y;
	long long X;
};

struct MinMax
{
	long long MinY;
	long long MaxY;
	long long MinX;
	long long MaxX;
};

vector<string> solution(vector<vector<int>> line) {

	vector<pair<Line, Line>> line_cartesian;
	for (int i = 0; i < line.size(); i++)
	{
		for (int j = i + 1; j < line.size(); j++)
		{
			line_cartesian.push_back({ {line[i][0], line[i][1], line[i][2]}, {line[j][0], line[j][1], line[j][2]}});
		}
	}

	// 나머지가 0 인 것들로만 dots push back
	Line l1, l2;
	long long x_val, y_val, mod;
	vector<Dot> dots;
	for (pair<Line, Line>& lines : line_cartesian)
	{
		l1 = lines.first;
		l2 = lines.second;

		mod = l1.A * l2.B - l1.B * l2.A;

		if (mod != 0.f)
		{
			y_val = l1.C * l2.A - l1.A * l2.C;
			x_val = l1.B * l2.C - l1.C * l2.B;
			if (y_val % mod == 0 && x_val % mod == 0)
			{
				dots.push_back({ y_val / mod, x_val / mod });
			}
		}
	}
	
	// min max 구해서 가장 작은 직사각형 크기 찾기
	MinMax minmax_val = { LLONG_MAX, LLONG_MIN , LLONG_MAX, LLONG_MIN };
	for (Dot& d : dots)
	{
		minmax_val.MaxY = max(minmax_val.MaxY, d.Y);
		minmax_val.MinY = min(minmax_val.MinY, d.Y);
		minmax_val.MaxX = max(minmax_val.MaxX, d.X);
		minmax_val.MinX = min(minmax_val.MinX, d.X);
	}

	vector<string> answer;
	string row = "";
	for (int i = 0; i <= minmax_val.MaxX - minmax_val.MinX; i++)
		row += '.';
	for (int i = 0; i <= minmax_val.MaxY - minmax_val.MinY; i++)
		answer.push_back(row);

	// y 값이 클수록 윗 row에 쌓이므로
	// y 기준은 max_y 로 해야함
	int stand_x, stand_y;
	stand_x = minmax_val.MinX;
	stand_y = minmax_val.MaxY;

	for (Dot& d : dots)
	{
		answer[int(stand_y - d.Y)][int(d.X - stand_x)] = '*';
	}
	
	return answer;
}
