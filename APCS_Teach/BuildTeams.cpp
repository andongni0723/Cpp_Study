#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

vector<vector<int>> gra(100010, vector<int>());
vector<pair<int, bool>> group(100010, make_pair(-1, false)); // group, visited
bool is_valid = false;

// return is group valid
bool bfs(int i)
{
    int current_group = 2;
    queue<int> que;
    if(group[i].second) return true; // has searched
    que.emplace(i);
    group[i].first = 1;
    group[i].second = true;
    

    while (!que.empty())
    {
        int ci = que.front(); que.pop();

        group[ci].second = true;

        current_group = group[ci].first == 1 ? 2 : 1; // change

        for (int j = 0; j < gra[ci].size(); j++)
        {
            if (group[gra[ci][j]].first == group[ci].first) return false;

            if(!group[gra[ci][j]].second) // not visited
            {
                group[gra[ci][j]].second = true;
                group[gra[ci][j]].first = current_group;

                que.emplace(gra[ci][j]);
            }
        }

    }
    
    return true;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        gra[a].emplace_back(b);
        gra[b].emplace_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        is_valid = bfs(i);
        if(!is_valid) break;
    }

    if(!is_valid)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << group[i].first << " ";
    }
}