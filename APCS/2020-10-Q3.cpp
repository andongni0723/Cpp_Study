#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";
#define MMAX -1e9;

int m, n;

vector<vector<int>> vec((int)60, vector<int>(11000, -1));
vector<vector<vector<lint>>> dp(60, vector<vector<lint>>(10010, vector<lint>(4, -1)));
// dir : 0 down , 1 left, 2 right
lint f(int y, int x, int dir)
{
    if(x == 0 || x >= n-1 || y <= 0 || y >= m-1) return vec[y][x];
    if(dp[y][x][dir] == -1)
    {
        lint result = MMAX;
        if(dir == 1 || dir == 0) // go left
        {
            if(x - 1 < 0) return MMAX;
            dp[y][x][dir] = max(dp[y][x][dir], f(y, x-1, 1));
        }
        if(dir == 2 || dir == 0) // go right
        {
            if(x + 1 >= n) return MMAX;
            dp[y][x][dir] = max(dp[y][x][dir], f(y, x+1, 2));
        }
        if(dir == 1 || dir == 2 || dir == 0) // go down
        {
            if(y + 1 >= m) return MMAX;
            dp[y][x][dir] = max(dp[y][x][dir], f(y+1, x, 0));
        }
    }
    return dp[y][x][dir];
}
int main()
{
    cin >> m >> n;

    int t;
    for (int iy = 0; iy < m; iy++)
    {
        for (int ix = 0; ix < n; ix++)
        {
            cin >> t;
            vec[iy][ix] = t;
        }
    }

    lint result = MMAX;
    for (int ix = 0; ix < n; ix++)
    {
        for (int dir = 0; dir < 3; dir++)
        {
            result = max(result, f(0, ix, dir));
        }
    }

    cout << result;
}
