#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int y, x, r, t;
vector<vector<int>> small(100, vector<int>(100));

bool compare(vector<vector<int>> vec, int iy, int ix, int target, int mode)
{
    if(mode == 0)
        if((iy + ix) % r == target) return true;
    if(mode == 1)
        if(vec[iy][ix] == target) return true;

    return false;
}

// [1, 1] [1, 2] [1, 3]
// [2, 1] [2, 2] [2, 3]
// [3, 1] [3, 2] [3, 3]
int search8(vector<vector<int>> vec, int iy, int ix, int target, int mode)
{
    int result = 0;
    bool yOut, xOut;
    if(ix - 1 > 0)
        if(compare(vec, iy, ix-1, target, mode)) result++;
    if(iy - 1 > 0)
        if(compare(vec, iy-1, ix, target, mode)) result++;
    if(ix + 1 <= x)
        if(compare(vec, iy, ix+1, target, mode)) result++;
    if(iy + 1 <= y)
        if(compare(vec, iy+1, ix, target, mode)) result++;

    if(iy-1 > 0 && ix-1 > 0)
        if(compare(vec, iy-1, ix-1, target, mode)) result++;
    if(iy-1 > 0 && ix+1 <= x)
        if(compare(vec, iy-1, ix+1, target, mode)) result++;
    if(iy+1 <= y && ix-1 > 0)
        if(compare(vec, iy+1, ix-1, target, mode)) result++;
    if(iy+1 <= y && ix+1 <= x)
        if(compare(vec, iy+1, ix+1, target, mode)) result++;

    return result;
}



int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> vec(100, vector<int>(100));

    cin >> y >> x >> r;

    for (int iy = 1; iy <= y; iy++)
    {
        for (int ix = 1; ix <= x; ix++)
        {
            cin >> t;
            vec[iy][ix] = t;
        }
    }

//    for (int iy = 0; iy <= y+1; iy++)
//    {
//        for (int ix = 0; ix <= x+1; ix++)
//        {
//            cout << vec[iy][ix] << " ";
//        }cout << endl;
//    }

    for (int iy = 1; iy <= y; iy++)
    {
        for (int ix = 1; ix <= x; ix++)
        {
            small[iy][ix] = search8(vec, iy, ix, vec[iy][ix], 0);
        }
    }

    for (int iy = 0; iy <= y+1; iy++)
    {
        for (int ix = 0; ix <= x+1; ix++)
        {
            cout << small[iy][ix] << " ";
        }cout << endl;
    }
}