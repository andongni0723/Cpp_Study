#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

lint OutputProduct(vector<lint> v, lint time)
{
    lint result = 0;
    for(auto it : v)
    {
        if (time / it > LLONG_MAX - result)
        {
            result = LLONG_MAX; // 避免溢位，設定為最大值
        }
        else
        {
            result += time / it;
        }
    }

    return result;
}

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, target, maxT = 0, t;
    cin >> n >> target;
    vector<lint> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);

        maxT = t > maxT ? t : maxT;
    }

    lint mid;
    lint L = 0, R = maxT * target;
    while (L <= R)
    {
        mid = (L + R) / 2;
        lint output = OutputProduct(vec, mid);

        if(output >= target)
        {
            R = mid - 1;
        }
        else if(output < target)
        {
            L = mid + 1;
        }
    }

    cout << L;
}