#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n;
    cin >> n;

    if(n % 3 == 0 && n % 5 == 0 && n % 7 == 0)
        cout << n;
    else if(n % 3 == 0)
        cout << n * 3;
    else if(n % 5 == 0)
        cout << n / 5;
    else if (n % 7 == 0)
        cout << n % 10;
    else
        cout << "None";

}