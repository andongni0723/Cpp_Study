#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

// [0,0] [0,1.txt] [0,2]
// [1.txt,0] [1.txt,1.txt] [1.txt,2]
// [2,0] [2,1.txt] [2,2]
// -> [y, x]

int x, y, t, s = 0;
vector<vector<int>> vec(200, vector<int>(200));

bool check(int iy, int ix, int change_y, int change_x)
{
    if(0 > iy + change_y || iy + change_y > y)
        return true;
    else if(0 > ix + change_x || ix + change_x > x)
        return true;
    else if(vec[iy + change_y][ix + change_x] == 0)
        return true;

    return false;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> y >> x;



    for (int iy = 0; iy < y; iy++)
    {
        for (int ix = 0; ix < x; ix++)
        {
            cin >> t;
            vec[iy][ix] = t;
        }
    }

    int result = 0;
    for (int iy = 0; iy < y; iy++)
    {
        for (int ix = 0; ix < x; ix++)
        {
            if(vec[iy][ix] != 1) continue;

            result = 0;
            if(check(iy, ix, 0, -1)) result++;
            if(check(iy, ix, 0, 1)) result++;
            if(check(iy, ix, 1, 0)) result++;
            if(check(iy, ix, 1, 0)) result++;

            s += result;
        }
    }

    cout << s;
}