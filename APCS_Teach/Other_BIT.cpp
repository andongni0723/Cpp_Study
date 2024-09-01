#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

struct BIT
{
    lint n;
    vector<lint> vec;

    BIT() : vec((int)2e5 + 10, 0) {};

    void init(lint n)
    {
        this->n = n;
    }

    lint lowbit(lint x)
    {
        return x & (-x);
    }

    void add(lint x, lint pos)
    {
        for(; pos <= n ; pos += lowbit(pos)) vec[pos] += x;
    }

    lint sum(lint n)
    {
        lint result = 0;
        for(; n > 0; n -= lowbit(n)) result += vec[n];
        return result;
    }
};



int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    BIT bit;
    lint n, q, t;
    cin >> n >> q;

    bit.init(n);
    for (lint i = 1; i <= n; i++)
    {
        cin >> t;
        bit.add(t, i);
    }

    lint a, b;
    for (lint i = 0; i < q; i++)
    {
        cin >> t >> a >> b;

        if(t == 1) // change value to t. t, pos, value
        {
            bit.add(b - (bit.sum(a) - bit.sum(a-1)), a);
        }
        else // get sum. t, l, r
        {
            cout << (bit.sum(b) - bit.sum(a-1)) << endl;
        }
    }

}
