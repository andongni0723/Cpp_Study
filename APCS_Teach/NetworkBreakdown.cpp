#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

struct disjointSet
{
    vector<int> f;
    vector<int> size;
    int currentComponentCount = 0;

    disjointSet() : f((int)1e6), size((int)1e6) {};

    void init(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            f[i] = i;
            size[i] = 1;
        }
        currentComponentCount = n;
    }

    int find(int n)
    {
        if(f[n] != n)
            return f[n] = find(f[n]);
        else
            return n;
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
    }

    void union_set(int a, int b)
    {
        if(same(a, b)) return;
        a = find(a);
        b = find(b);
        if(f[a] < f[b]) swap(a, b);
        // now a > b, for all
        f[b] = a;
        size[a] += size[b];
        currentComponentCount--;
    }

};

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    disjointSet djs;
//    vector<pair<int, int>> vec;
    multiset<pair<int, int>> vec;
    vector<pair<int, int>> destruct;
    vector<pair<int, int>> construct;
    int n, c, d;
    cin >> n >> c >> d;
    djs.init(n);

    int t1, t2;
    for (int i = 0; i < c; i++)
    {
        cin >> t1 >> t2;
        vec.emplace(t1, t2);
    }
    for (int i = 0; i < d; i++)
    {
        cin >> t1 >> t2;
        destruct.emplace_back(t1, t2);
    }

    // build construct = vec - destruct
    for(auto d : destruct)
    {
        vec.erase(d);
    }
    for(auto r : vec)
    {
        construct.emplace_back(r);
    }
//    for(auto it : vec)
//    {
//        bool isDestruct = false;
//        for(auto it1 : destruct)
//        {
//            if(it == it1)
//            {
//                isDestruct = true;
//                break;
//            }
//        }
//
//        if(!isDestruct)
//            construct.emplace_back(it);
//    }

    // build base road
    for (int i = 0; i < c-d; i++)
    {
        djs.union_set(construct[i].first, construct[i].second);
    }

    // build destruct road and record component count
    vector<int> result;
    reverse(destruct.begin(), destruct.end());
    for (int i = 0; i < d; i++)
    {
        result.emplace_back(djs.currentComponentCount);
        djs.union_set(destruct[i].first, destruct[i].second);
    }

    // the result reverse is ans
    reverse(result.begin(), result.end());
    for(auto it : result)
        cout << it << " ";
}