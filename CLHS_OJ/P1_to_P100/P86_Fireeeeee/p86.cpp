#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

// [0,0] [0,1.txt] [0,2]
// [1.txt,0] [1.txt,1.txt] [1.txt,2]
// [2,0] [2,1.txt] [2,2]
// -> [y, x]

lint x, y, q, t;
vector<vector<int>> vec(1000, vector<int>(1000));
vector<vector<int>> temp_vec(1000, vector<int>(1000));
vector<vector<int>> last_vec(1000, vector<int>(1000));
bool isSame = false;

void check_and_write_fire(int iy, int ix, int change_y, int change_x)
{
    if(0 <= iy+change_y && iy+change_y <= y &&
       0 <= ix+change_x && ix+change_x <= x)
    {
        if(temp_vec[iy+change_y][ix+change_x] != -1)
            temp_vec[iy+change_y][ix+change_x] = 1;
    }
}

void fire()
{
    temp_vec = vec;

    for (lint iy = 0; iy < y; iy++)
    {
        for(lint ix = 0; ix < x ; ix++)
        {
            if(vec[iy][ix] == 1)
            {
                check_and_write_fire(iy, ix, -1, 0);
                check_and_write_fire(iy, ix, 1, 0);
                check_and_write_fire(iy, ix, 0, -1);
                check_and_write_fire(iy, ix, 0, 1);
            }
        }
    }


    vec = temp_vec;

    if(vec == last_vec)
    {
        isSame = true;
    }
    last_vec = vec;

}


int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> y >> x;

    for (lint iy = 0; iy < y; iy++)
    {
        for(lint ix = 0; ix < x ; ix++)
        {
            cin >> t;
            vec[iy][ix] = t;
        }
    }

    cin >> q;
    for (lint i = 0; i < q; i++)
    {
        fire();

        if(isSame) break;
    }

    for (lint iy = 0; iy < y; iy++)
    {
        for(lint ix = 0; ix < x ; ix++)
        {
            cout << vec[iy][ix] << " ";
        }
        cout << endl;
    }
}