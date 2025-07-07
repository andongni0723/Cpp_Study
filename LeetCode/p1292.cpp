#include <bits/stdc++.h>
using namespace std;
#define lint long long;
#define endl "\n"

class Solution {
private:
    vector<vector<int>> prefix;

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        prefix.resize(mat.size() + 1, vector<int>(mat[0].size() + 1));
        for(int y = 0 ; y < mat.size() ; ++y)
            for(int x = 0 ; x < mat[y].size() ; ++x)
                prefix[y+1][x+1] = prefix[y+1][x] + prefix[y][x+1] - prefix[y][x] + mat[y][x];

        // b search
        int L = 0;
        int R = min(mat.size(), mat[0].size());
        while(L < R)
        {
            int mid = (L + R + 1) / 2;
            if (check(mat, mid, threshold))
                L = mid;
            else
                R = mid - 1;
        }

        return L;
    }

    bool check(vector<vector<int>>& mat, int n, int threshold)
    {
        for(int y = 0 ; y < mat.size() ; ++y)
            for(int x = 0 ; x < mat[y].size() ; ++x)
            {
                if(x + n > mat[0].size() || y + n > mat.size()) continue;
                int a = prefix[y+n][x+n] - prefix[y][x+n] - prefix[y+n][x] + prefix[y][x];
                if(a <= threshold) return true;
            }
        return false;
    }
};

int main()
{
    auto s = Solution();
    vector<vector<int>> vec = {{1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2}};
    s.maxSideLength(vec, 1);
}