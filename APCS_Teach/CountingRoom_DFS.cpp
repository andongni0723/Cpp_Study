#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int n, m, result = 0;
string t;
vector<string> vec;
vector<vector<bool>> bool_vec(1010,
                              vector<bool>(1010, false)); // has found


int y[4] = {1,-1,0,0};
int x[4] = {0,0,1,-1};
int c_y = y[0], c_x = x[0];

void dfs(int in, int im)
{
    bool_vec[in][im] = true;

    for (int i = 0; i < 4; i++)
    {
        c_y = y[i];
        c_x = x[i];
        int c_find_y = in + c_y;
        int c_find_x = im + c_x;

        if((c_find_y < 0 || c_find_y >= n) ||
           (c_find_x < 0 || c_find_x >= m)) continue;

        if(vec[c_find_y][c_find_x] == '.' &&
           !bool_vec[c_find_y][c_find_x])
        {
            bool_vec[c_find_y][c_find_x] = true;
            dfs(c_find_y, c_find_x);
        }
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m; // y x

    for (int in = 0; in < n; in++)
    {
        cin >> t;
        vec.emplace_back(t);
    }

    for (int in = 0; in < n; in++)
    {
        for (int im = 0; im < m; im++)
        {
            if(!bool_vec[in][im] && vec[in][im] == '.') // has not been found
            {
                dfs(in, im);
                result++;
            }
        }
    }

    cout << result;

}