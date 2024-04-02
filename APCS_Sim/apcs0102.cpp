#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    vector<unordered_set<int>> pondGroup(30, unordered_set<int>());
    vector<lint> pondSumWeight(30);
    vector<bool> pondWeightExceed(30);
    int n, m, k, w, q;
    int t;
    cin >> n >> m >> k >> w >> q;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> t;
            pondGroup[i].insert(t);
            pondGroup[t].insert(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> t;
            pondSumWeight[i] += t;
        }
    }


    for (int i = 1; i <= n; i++)
    {
        if(pondSumWeight[i] > w)
            pondWeightExceed[i] = true;
    }

    int c1p, c1w, c2p, c2w;
    for (int i = 0; i < q; i++)
    {
        cin >> c1p >> c1w >> c2p >> c2w;
        if(pondGroup[c1p].find(c2p) != pondGroup[c1p].end())
        {
            pondSumWeight[c1p] -= c1w;
            pondSumWeight[c1p] += c2w;
            pondSumWeight[c2p] -= c2w;
            pondSumWeight[c2p] += c1w;

            pondWeightExceed[c1p] = pondSumWeight[c1p] > w;
            pondWeightExceed[c2p] = pondSumWeight[c2p] > w;

            cout << "YES" << " ";
        }
        else
        {
            cout << "NO" << " ";
        }

        // Calc sentiment bad fish
        int result = 0;
        for (int j = 1; j <= n; j++)
        {
            if(pondWeightExceed[j])
                result += k;
        }

        cout << result << endl;
    }
}