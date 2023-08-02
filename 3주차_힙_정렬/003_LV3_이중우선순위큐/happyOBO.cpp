#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
	map<int, int> num_frequency;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	priority_queue<int, vector<int>, less<int>> max_heap;

	string command, element;
	int e, top_element, heap_size = 0;
	for (string& op : operations)
	{
		stringstream ss(op);
		ss >> command >> element;

		e = stoi(element);
		// 추가
		if (command == "I")
		{
			min_heap.push(e);
			max_heap.push(e);
			if (num_frequency.find(e) == num_frequency.end()) num_frequency.insert({ e, 1 });
			else num_frequency[e]++;
			heap_size++;
		}
		// 삭제
		else if (0 < heap_size)
		{
			// 최대값 삭제
			if (0 < e)
			{
				top_element = max_heap.top();  max_heap.pop();
				heap_size--;
				num_frequency[top_element]--;
			}
			// 최소값 삭제
			else
			{
				top_element = min_heap.top();  min_heap.pop();
				heap_size--;
				num_frequency[top_element]--;
			}
		}
	}

	int result_max = 0, result_min = 0;
	if (0 < heap_size)
	{
		// 삭제 되었던 부분은 걸러내기
		while (!max_heap.empty())
		{
			result_max = max_heap.top(); max_heap.pop();
			if (0 < num_frequency[result_max])
			{
				break;
			}
			result_max = 0;
		}

		while (!min_heap.empty())
		{
			result_min = min_heap.top(); min_heap.pop();
			if (0 < num_frequency[result_min])
			{
				break;
			}
			result_min = 0;
		}
	}

	return { result_max, result_min };
}