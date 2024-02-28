#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    for (int i = n.size()-1 ; i > -1 ; i--)
    {
        cout << n[i];
    }
}