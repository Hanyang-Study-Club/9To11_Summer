#include <bits/stdc++.h>
using namespace std;


int solution(vector<vector<string>> clothes) {
    
    map<string,int> clothes_dict;
    for(auto cloth : clothes)
    {
		if (clothes_dict.find(cloth[1]) != clothes_dict.end())
			clothes_dict[cloth[1]]++;
		else
			clothes_dict.insert(make_pair(cloth[1], 1));
    }
    
    int answer = 1;
    
    for(auto cloth : clothes_dict)
    {
        answer *= (cloth.second + 1);
    }
    
    return answer - 1;
}