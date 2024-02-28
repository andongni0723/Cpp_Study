#include <bits/stdc++.h>
using namespace std;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    long long int n, t, sum = 0;
    vector<long long int> vec;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.push_back(t);
    }

    sort(vec.begin(), vec.end());

    for(long long int it : vec)
    {
        if(it >= sum + 2)
        {
            cout << sum + 1;
            return 0;
        }
        else
        {
            sum += it;
        }

    }

    cout << sum+1;
}