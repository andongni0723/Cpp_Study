// q836. 1. 小心陷阱
#include <bits/stdc++.h>
using namespace std;
#define lint long long;
#define endl "\n";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, x1, y1, x2, y2;
    cin >> k >> x1 >> y1 >> x2 >> y2;

    int pos = 0;
    while(k > 0)
    {
        pos += k;
        if (pos % x1 == 0)
            k -= y1;
        if (pos % x2 == 0)
            k -= y2;
    }
    cout << pos;
}