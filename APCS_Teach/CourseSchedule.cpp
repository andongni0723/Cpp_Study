#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int n, m, t1, t2;
vector<vector<int>> graph((int)1e5 + 10, vector<int>());
vector<int> sorted;
vector<bool> visited((int)1e5 + 10);
vector<int> in((int)1e5 + 10, 0);


void bfs(int i)
{
    queue<int> que;
    que.push(i);
    sorted.emplace_back(i);
    visited[i] = true;

    while (!que.empty())
    {
        int current_num = que.front(); que.pop();

        for(auto it : graph[current_num])
        {
            in[it]--;
            if(in[it] == 0 && !visited[it])
            {
                visited[it] = true;
                que.push(it);
                sorted.emplace_back(it);
            }
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
        cin >> t1 >> t2;
        graph[t1].emplace_back(t2);
        in[t2]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if(!visited[i] && in[i] == 0)
        {
            bfs(i);
        }
    }

    if(sorted.size() == n)
    {
        for(auto it : sorted)
        {
            cout << it << " ";
        }
    }
    else
        cout << "IMPOSSIBLE";
}