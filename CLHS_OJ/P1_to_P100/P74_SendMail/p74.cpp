#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, old_count = 0, young_count = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> m;
        if(m == 1 || m == 3 || m == 5 || m == 7)
            young_count++;
        else
            old_count++;
    }

    if(young_count < old_count)
        cout << "Win";
    else
        cout << "Lose";
}