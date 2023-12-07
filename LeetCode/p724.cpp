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
    int pivotIndex(vector<int> &nums)
    {

        long long int listSum = 0;
        long long int currentSum = 0;

        // Get sum of all list element
        for (int i = 0; i < nums.size(); i++)
        {
            listSum += nums[i];
        }

        // For each all element and minus each element
        // to find sum is the total sum divided by 2
        for (int i = 0; i < nums.size(); i++)
        {
            currentSum += nums[i];

            if ((currentSum - nums[i]) * 2 == listSum - nums[i])
            {
                return i;
            }
        }

        return -1;
    }
};