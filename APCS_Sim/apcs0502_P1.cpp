#include <bits/stdc++.h>
using namespace std;
#define lint long long

int main()
{
    int n, m, f, q;
    pair<int, int> midPos;
    cin >> n >> m >> f >> q;
    vector<vector<int>> vec(50, vector<int>(50)); // 0-base
    vector<vector<int>> spacVec(50, vector<int>(50)); // 0-base

    int t;
    for (int iy = 0; iy < n; iy++)
    {
        for (int ix = 0; ix < m; ix++)
        {
            cin >> t;
            vec[iy][ix] = t;
        }
    }

    int t1, t2 ,spac;
    int midSPAC;
    for (int i = 0; i < f; i++)
    {
        cin >> t1 >> t2 >> spac;
        spacVec[t1][t2] = spac;

        if(i == 0)
        {
            midSPAC = spacVec[t1][t2];
            midPos = make_pair(t1, t2);
        }
    }

    for (int i = 0; i < q; i++)
    {
        cin >> t1 >> t2;
        pair<int, int> qPos = make_pair(t1, t2);

        int d = abs(midPos.first - qPos.first) + abs(midPos.second - qPos.second);

        int cSPAC = midSPAC - d + vec[t1][t2];
        cSPAC = max(0, cSPAC);
        cSPAC = min(50, cSPAC);

        if(i+i != q)
            cout << cSPAC << endl;
        else
            cout << cSPAC;
    }
}

