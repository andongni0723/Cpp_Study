#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    char lastChar = {};
    int count = 0, maxCount = 0;
    cin >> n;

    for (int i = 0; i < n.size(); i++)
    {
        if(lastChar == n[i] || i == 0)
        {
            count++;
        }
        else
        {
            maxCount = count > maxCount ? count : maxCount;
            count = 1;
        }

        lastChar = n[i];
    }

    maxCount = count > maxCount ? count : maxCount;
    cout << maxCount;

}