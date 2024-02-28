#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    string n;

    getline(cin, n, '/');
    cout << (stoi(n) - 5) / 2 << "/";

    getline(cin, n, '/');
    cout << stoi(n) + 9 << "/";

    getline(cin, n, '/');
    cout << stoi(n) / 2 + 5;
}