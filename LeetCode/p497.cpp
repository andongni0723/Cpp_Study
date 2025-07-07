#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define endl "\n"

class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        prefix.resize(rects.size() + 1);
        int i = 0;
        for (auto rect : rects)
        {
            int x = rect[2] - rect[0] + 1;
            int y = rect[3] - rect[1] + 1;
            areas.emplace_back(x * y);
            prefix[i+1] = x * y + prefix[i];
            i++;
        }
    }

    vector<int> pick() {
        uniform_int_distribution<lint> dist(0, prefix.back() - 1);
        int r = dist(rng);
        int idx = upper_bound(prefix.begin(), prefix.end(), r) - prefix.begin() - 1;
        int x = dist(rng) % (rects[idx][2] - rects[idx][0] + 1) + rects[idx][0];
        int y = dist(rng) % (rects[idx][3] - rects[idx][1] + 1) + rects[idx][1];
        return {x, y};
    }

private:
    vector<vector<int>> rects;
    vector<int> areas;
    vector<int> prefix;
    mt19937 rng{random_device{}()};
};


int main()
{
    vector<vector<int>> rects{{-2, -2, 1, 1}, {2, 2, 4, 6}};

    auto* obj = new Solution(rects);
    vector<int> param_1 = obj->pick();
    vector<int> param_2 = obj->pick();
    vector<int> param_3 = obj->pick();
    vector<int> param_4 = obj->pick();
    vector<int> param_5 = obj->pick();
}