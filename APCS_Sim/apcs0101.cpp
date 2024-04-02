#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p, sitLeave, standLeave, d;

    cin >> n >> p >> sitLeave >> standLeave >> d;

    int stand = max(p - n, 0);
    int empty = max(n - p, 0);
    int sit = n - empty;

    int newP = p - sitLeave - standLeave;
    int newSit = sit - sitLeave;
    int newStand = stand - standLeave;

    if(newSit + newStand + d <= n)
    {
        cout << "Happy :>" << endl;
        cout << n - (newSit + newStand + d);
    }
    else
    {
        cout << "Sad :((" << endl;
        cout << newSit + newStand + (d-1) - n;
    }
}