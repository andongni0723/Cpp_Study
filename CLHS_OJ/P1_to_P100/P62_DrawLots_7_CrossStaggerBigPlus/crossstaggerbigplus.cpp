#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h;
    int lots_x, lots_y;
    bool isStand = false;

    cin >> w >> h;
    cin >> lots_x >> lots_y;

    isStand = lots_y % 2 == 1;

    for (int y = 1; y <= h; y++)
    {
        for (int x = 1; x <= w; x++)
        {
            if(x == lots_x && y == lots_y)
            {
                cout << "*";
            }
            else if(abs(lots_y - y) == abs(lots_x - x) && isStand)
            {
                cout << "O";
            }
            else
            {
                cout << "-";
            }
        }
        isStand = !isStand;
        cout << endl;
    }
}
