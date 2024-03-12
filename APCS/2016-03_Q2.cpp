#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

vector<vector<int>> vec(100, vector<int>(100, -1));
vector<vector<int>> vec1(100, vector<int>(100, -1));
vector<int> process;
int current_vec = 0; // 0 : vec, 1.txt : vec1
int c_y, c_x, m, t;

void flip(vector<vector<int>> &old_vec, vector<vector<int>> &target_vec)
{
    float mid = (c_y-1) / 2.0;
    for (int iy = 0; iy < c_y; iy++)
    {
        for (int ix = 0; ix < c_x; ix++)
        {
            if(c_y % 2 == 1 && iy == (c_y-1) / 2)
                target_vec[iy][ix] = old_vec[iy][ix];
            else
                target_vec[iy + (mid - iy) * 2][ix] = old_vec[iy][ix];
        }
    }
}

void rotate(vector<vector<int>> &old_vec, vector<vector<int>> &target_vec)
{
    for (int iy = 0; iy < c_y; iy++)
    {
        for (int ix = 0; ix < c_x; ix++)
        {
            target_vec[c_x-1 - ix][iy] = old_vec[iy][ix];
        }
    }
    int temp = c_x;
    c_x = c_y;
    c_y = temp;

}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c_y >> c_x >> m;

    for (int iy = 0; iy < c_y; iy++)
    {
        for (int ix = 0; ix < c_x; ix++)
        {
            cin >> t;
            vec[iy][ix] = t;
        }
    }


    for (int i = 0; i < m; i++)
    {
        cin >> t;
        process.emplace_back(t);
    }

    for (int i = m-1; i >= 0; i--)
    {
        // 0 : rotate
        // 1.txt : flip
        t = process[i];

        if(t == 0) // 0 : rotate
        {
            if(current_vec == 0)
                rotate(vec, vec1);
            else
                rotate(vec1, vec);

            current_vec = current_vec == 0 ? 1 : 0;
        }
        else // 1.txt : flip
        {
            if(current_vec == 0)
                flip(vec, vec1);
            else
                flip(vec1, vec);

            current_vec = current_vec == 0 ? 1 : 0;
        }
    }


    cout << c_y << " " << c_x << endl;
    for (int iy = 0; iy < c_y; iy++)
    {
        for (int ix = 0; ix < c_x; ix++)
        {
            if(current_vec == 0)
                cout << vec[iy][ix];
            else
                cout << vec1[iy][ix];

            if(ix != c_x-1)
                cout << " ";
        }
        cout << endl;
    }


}