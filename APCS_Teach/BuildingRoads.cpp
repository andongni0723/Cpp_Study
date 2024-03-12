#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";


int n, m, t1, t2, component = 0;
vector<vector<int>> graph((int)1e6 + 10, vector<int>());
vector<bool> visited((int)1e6 + 10, false);
vector<pair<int, int>> road;

void dfs(int i)
{
    visited[i] = true;
    for(auto j : graph[i])
    {
        if(!visited[j])
        {
            dfs(j);
        }
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
//        cout << "D";
        cin >> t1 >> t2;

        graph[t1].emplace_back(t2);
        graph[t2].emplace_back(t1);
    }

    for (int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            if(i != 1)
                road.emplace_back(1, i);

            dfs(i);
            component++;
        }
    }

    cout << component - 1 << endl;

    for(auto it : road)
    {
        cout << it.first << " " << it.second << endl;
    }
}