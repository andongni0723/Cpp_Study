#include <bits/stdc++.h>
using namespace std;
int main() {}

static auto __ = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int i = 0;
        for (i; i < nums.size(); i++)
        {
            // The element is bigger than target
            if (nums[i] > target)
            {
                break;
            }
            // Found
            else if (nums[i] == target)
            {
                return i;
            }
        }

        // Not Found
        return i;
    }
};