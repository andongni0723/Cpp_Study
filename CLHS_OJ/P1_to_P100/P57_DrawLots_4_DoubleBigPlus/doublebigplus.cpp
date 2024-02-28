#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h;
    int center1_x, center1_y;
    int center2_x, center2_y;
    int x = 0, y = 0;

    cin >> w >> h;
    cin >> center1_x >> center1_y;
    cin >> center2_x >> center2_y;

    for (int y = 1; y <= h; y++)
    {
        for (int x = 1; x <= w; x++)
        {
            // Var
            int in_line1 = (x == center1_x || y == center1_y);
            int in_line2 = (x == center2_x || y == center2_y);

            if (x == center1_x && y == center1_y || // is line center
                x == center2_x && y == center2_y)
            {
                cout << "*";
            }
            else if (in_line1 || in_line2) // in line 1.out or line2
            {
                cout << (in_line1 && in_line2 ? "#" : "O");
            }
            else
            {
                cout << "-";
            }
        }

        cout << endl;
    }
}