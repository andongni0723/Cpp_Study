#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int, bool> arr[40][40];
    pair<int, int> quiz_pos(0,0);
    int x, y, t;
    cin >> y >> x;

    for (int iy = 0; iy < y; iy++)
    {
        for (int ix = 0; ix < x; ix++)
        {
            cin >> t;
            switch (t)
            {
                case 0:
                    arr[ix][iy].first = 0;
                    break;
                case 87:
                    arr[ix][iy].first = 87;
                    quiz_pos = make_pair(ix, iy);
                    break;
                case -1:
                    arr[ix][iy].first = -1;
                    arr[ix][iy-1].second = true;
                    arr[ix+1][iy-1].second = true;
                    arr[ix+1][iy].second = true;
                    arr[ix+1][iy+1].second = true;
                    arr[ix][iy+1].second = true;
                    arr[ix-1][iy+1].second = true;
                    arr[ix-1][iy].second = true;
                    arr[ix-1][iy-1].second = true;
                    break;
            }

        }
    }

    if(arr[quiz_pos.first][quiz_pos.second].second)
    {
        cout << "YES!YES!YES!";
    }
    else
    {
        cout << "NO!NO!NO!";
    }
}

//-1.txt.-1.txt 0,-1.txt +1.txt, -1.txt
//-1.txt,0  0  +1.txt,0
//-1.txt,+1.txt 0,+1.txt +1.txt,+1.txt
// (0, 0) (1.txt, 0)