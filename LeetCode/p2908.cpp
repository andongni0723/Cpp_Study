#include <bits/stdc++.h>
using namespace std;
#define lint long long;
#define endl "\n"

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        auto size = nums.size();
        int minR = 1e3;
        for(int i = 0 ; i < size ; ++i)
        {
            for(int j = i+1 ; j < size ; ++j)
            {
                for(int k = j+1 ; k < size ; ++k)
                {
                    if(nums[i] < nums[j] && nums[k] < nums[j])
                    {
                        minR = min(minR, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }

        return (minR == 1e3) ? -1 : minR;
    }
};