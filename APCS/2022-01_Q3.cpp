#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

vector<vector<bool>> seen(60000, vector<bool>(60000));


int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, result = 0;
    vector<string> vec;
    string t;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool isDiff = false;
            if(i == j) continue;
            if(seen[j][i]) continue;
            seen[i][j] = true;

            if((vec[i].size() + vec[j].size()) % 2 == 1) continue;

            string a = vec[i];
            a += vec[j];

            int mid = (int)a.size() / 2;
            for (int k = 0; k < mid; k++)
            {
                if(a[k] != a[mid + k])
                {
                    isDiff = true;
                    break;
                }
            }

            if(isDiff)
                continue;
            else
                result++;
        }
    }

    cout << result;
}