#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0, R = height.size()-1;
        int maxArea = 0;
        while (L!=R)
        {
            if(height[L] >= height[R])
            {
                R--;
            }
            else
            {
                L++;
            }

            maxArea = max(maxArea, min(height[L], height[R]) * abs(R - L));
        }

        maxArea = min(height[L], height[R]) * abs(R - L);
        return maxArea;
    }
};



int main()
{
    Solution s = Solution();
    int x;
    cin >> x;
    // cout << s.maxArea();
}