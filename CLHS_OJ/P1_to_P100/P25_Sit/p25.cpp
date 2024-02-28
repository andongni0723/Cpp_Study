#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, t, boy_count = 0, girl_count = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        switch(t)
        {
            case 1:
                boy_count++;
                break;
            case 2:
                girl_count++;
                break;
        }
    }

    cout << boy_count << endl << girl_count;
}