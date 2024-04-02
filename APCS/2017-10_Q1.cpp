#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int a1, b1, r;
    bool a, b;
    bool haveAns = false;
    cin >> a1 >> b1 >> r;

    a = (bool)a1;
    b = (bool)b1;

    if((a && b) == r)
    {
        haveAns = true;
        cout << "AND" << endl;
    }

    if((a || b) == r)
    {
        haveAns = true;
        cout << "OR" << endl;
    }

    if((a ^ b) == r)
    {
        haveAns = true;
        cout << "XOR" << endl;
    }

    if(!haveAns)
    {
        cout << "IMPOSSIBLE";
    }

}