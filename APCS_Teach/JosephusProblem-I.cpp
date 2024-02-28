#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    queue<int> que;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        que.emplace(i);
    }

    while(!que.empty())
    {
        int t = que.front();
        que.pop();
        que.emplace(t);
        cout << que.front() << " ";
        que.pop();
    }
}
