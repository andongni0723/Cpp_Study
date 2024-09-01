#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<lint>> vec(30, vector<lint>(30, 0));
    int y, x, t, c;
    for (int i = 0; i < n; i++)
    {
        cin >> y >> x >> t >> c;
        for (int iy = 0; iy < h; iy++)
        {
            for (int ix = 0; ix < w; ix++)
            {
                if(abs(ix - x) + abs(iy - y) <= t)
                {
                    vec[iy][ix] += c;
                }
            }
        }
    }
    for (int iy = 1; iy < h; iy++)
    {
        for (int ix = 0; ix < w; ix++)
        {
            cout << vec[iy][ix] << " ";
        }
        cout << endl;
    }
}
