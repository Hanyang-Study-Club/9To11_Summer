#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int num_size = nums.size();
    
    set<int> nums_set;
    for(int i =0; i < num_size; i++)
    {
        if(nums_set.find(nums[i]) == nums_set.end())
        {
            nums_set.insert(nums[i]);
        }
    }

    if(nums_set.size() < num_size / 2)
        return nums_set.size();
    else
        return num_size / 2;
}