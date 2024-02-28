#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int nums[5][5] = {{1, 2, 9, 10, 25},
                  {4, 3, 8, 11, 24},
                  {5, 6, 7, 12, 23},
                  {16, 15, 14, 13, 22},
                  {17, 18, 19, 20, 21}};

    int n;
    cin >> n;
    int y, x;

    for (int i = 0; i < n; i++)
    {
        cin >> y >> x;
        cout << nums[y - 1][x - 1] << endl;
    }
}