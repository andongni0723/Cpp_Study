#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int y, x, r, t;
    vector<int> vec(100);
    vector<int> small(100);


    cin >> y >> x >> r;

    for (int i = 0; i < x; i++)
    {
        cin >> t;
        vec[i] = t;
    }

//    for (int iy = 0; iy <= y+1; iy++)
//    {
//        for (int ix = 0; ix <= x+1; ix++)
//        {
//            cout << vec[iy][ix] << " ";
//        }cout << endl;
//    }

    for (int i = 0; i < x; i++)
    {
        int result = 0;
        if(i != 0 && i != x-1)
        {
            if((vec[i-1] + vec[i+1]) % r == vec[i])
                result++;
        }
        small[i] = result;
    }

//    for (int i = 0; i < x; i++)
//    {
//        cout << small[i] << " ";
//    }cout << endl;


    int ans = 0;
    for (int i = 0; i < x; i++)
    {
        if(i != 0)
        {
            if(small[i-1] == small[i])
                ans++;
        }
        if(i != x-1)
        {
            if(small[i+1] == small[i])
                ans++;
        }
    }

    cout << ans/2;
}