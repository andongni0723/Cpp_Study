#include <bits/stdc++.h>
using namespace std;
int main() {}

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashMap;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            if(hashMap.empty()) continue;
            if(hashMap.find(target - nums[i]) != hashMap.end())
            {
                result.push_back(i);
                result.push_back(i+1);
            }
            else
            {
                hashMap[nums[i]] = nums[i];
            }
        }

        return result;
    }
};