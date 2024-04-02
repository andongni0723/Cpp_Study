#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    string num;
    cin >> num;

    int result;

    for (int i = 0; i < num.size(); i++)
    {
        if(i % 2 == 0)
            result += num[i] - '0';
        else
            result -= num[i] - '0';
    }

    cout << abs(result);
}