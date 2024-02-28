#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

vector<lint> vec(1000000 + 5);

lint f(int a)
{
    if (a == 0) return 1;

    if(vec[a] != -1) // find
    {
        return vec[a];
    }
    else
    {
        if (a <= 6)
        {
            lint result = 0;
            for (int i = 0; i < a; i++)
            {
                result += f(i);
            }

            return vec[a] = result % (lint)(1e9 + 7);
        } else
        {
            return vec[a] = (f(a - 1) + f(a - 2) + f(a - 3) + f(a - 4) + f(a - 5) + f(a - 6)) % (lint)(1e9 + 7);
        }
    }
}

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n;
    cin >> n;

    fill(vec.begin(), vec.end(), -1);
    cout << f(n);
}