#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

struct disjointSet
{
    vector<lint> vec;
    vector<lint> size;
    lint componentCount = 0;
    lint maxSize = 1;

    disjointSet() : vec((int)1e5 + 10), size((int)1e5 + 10) {}

    void init(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            vec[i] = i;
            size[i] = 1;
        }

        componentCount = n;
    }

    int find(int x)
    {
        if(vec[x] != x)
            return vec[x] = find(vec[x]);
        else
            return x;
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
    }

    void union_set(int a, int b)
    {
        if(find(a) == find(b)) return;

        int x = find(a);
        int y = find(b);
        if(size[x] < size[y]) swap(x, y);
        // now x > y, x for all
        size[x] += size[y];
        vec[y] = vec[x];
        size[y] = 0;

        maxSize = max(size[x], maxSize);
        componentCount--;
    }
};

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    disjointSet djs;
    int n, m;
    cin >> n >> m;
    djs.init(n);

    int t1, t2;
    for (int i = 0; i < m; i++)
    {
        cin >> t1 >> t2;
        djs.union_set(t1, t2);
        cout << djs.componentCount << " " << djs.maxSize << endl;
    }

}