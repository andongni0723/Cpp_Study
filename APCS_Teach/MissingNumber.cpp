#include <bits/stdc++.h>
using namespace std;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    unordered_map<int, bool> numHave;
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        cin >> t;
        numHave[t] = t;
    }

    for (int i = 1; i <= n; i++)
    {
        if(numHave.find(i) == numHave.end())
        {
            cout << i;
            break;
        }
    }
}