#include <bits/stdc++.h>
using namespace std;
#define lint long long;
#define endl "\n"

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for (int iy = 0; iy < grid.size(); ++iy)
        {
            for (int ix = 0; ix < grid[iy].size(); ++ix)
            {
                if (iy + 1 < grid.size() &&
                    grid[iy][ix] == grid[iy + 1][ix])
                    return false;
                if (ix + 1 < grid[iy].size() &&
                    grid[iy][ix] != grid[iy][ix + 1])
                    return false;
            }
        }
        return true;                                // 全檢查通過
    }
};
