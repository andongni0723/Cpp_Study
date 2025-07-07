#include <bits/stdc++.h>
using namespace std;
#define lint long long;
#define endl "\n"

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> vec(mat.size()); // count, idx
        int c = 0;
        for(int i = 0 ; i < mat.size() ; ++i)
        {
            c = 0;
            for(int j = 0 ; j < mat[i].size() ; ++j)
                if(mat[i][j]) c++;

            vec[i] = make_pair(c, i);
        }

        sort(vec.begin(), vec.end());

        vector<int> r;
        for(int i = 0 ; i < k ; ++i)
            r.emplace_back(vec[i].second);

        return r;
    }
};