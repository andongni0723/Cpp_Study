#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h;
    int lots_x, lots_y;
    int x = 0, y = 0;
    int edge_other_x1 = -1, edge_other_y1 = -1;
    int edge_other_x2 = -1, edge_other_y2 = -1;

    cin >> w >> h;
    cin >> lots_x >> lots_y;

    // The center position are close to the edge
    if (lots_x == 1)
    {
        edge_other_x1 = 8;
        edge_other_y1 = lots_y;
    }
    else if (lots_x == 8)
    {
        edge_other_x1 = 1;
        edge_other_y1 = lots_y;
    }

    if (lots_y == 1)
    {
        edge_other_x2 = lots_x;
        edge_other_y2 = 8;
    }
    else if (lots_y == 8)
    {
        edge_other_x2 = lots_x;
        edge_other_y2 = 1;
    }

    for (int y = 1; y <= h; y++)
    {
        for (int x = 1; x <= w; x++)
        {
            if (x == lots_x && y == lots_y) // Center
            {
                cout << "*";
            }
            else if (x == lots_x && y == lots_y - 1 ||           // up
                     x == lots_x && y == lots_y + 1 ||           // down
                     x == lots_x - 1 && y == lots_y ||           // left
                     x == lots_x + 1 && y == lots_y ||           // right
                     x == edge_other_x1 && y == edge_other_y1 || // other position when center close to edge
                     x == edge_other_x2 && y == edge_other_y2)
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