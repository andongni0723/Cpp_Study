#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h;
    int lots_x, lots_y;
    //int x = 0, y = 0;

    cin >> w >> h;
    cin >> lots_x >> lots_y;

    for (int y = 1; y <= h; y++)
    {
        for (int x = 1; x <= w; x++)
        {
            if(x == lots_x && y == lots_y)
            {
                cout << "*";
            }
            else if(abs(lots_y - y) == abs(lots_x - x))
            {
                cout << "O";
            }
            else
            {
                cout << "-";
            }
        }

        cout << endl;
    }
}
