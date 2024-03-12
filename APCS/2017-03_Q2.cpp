#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int n, t, group = 0;
vector<int> vec;
vector<bool> visited((int)1e6);

void dfs(int i)
{
    //visited true
    //for j in i.connected
    //check not visited
    //dfs(j)

    visited[i] = true;
    if(vec[i] == i) return;
    if(!visited[vec[i]]) dfs(vec[i]);
}
int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);
    }

    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(vec[i]);
            group++;
        }
    }

    cout << group;
}