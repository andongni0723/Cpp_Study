#include <bits/stdc++.h>
using namespace std;

int w, h;               // the seat width, height
int center_x, center_y; // the center seat of lots position
int x = 0, y = 0;       // current print position
int is_stand = 0;       // bool

/// @brief According to center position to
// calc the "big plus" first people in line be standing or not
void check_update_is_stand_value(int _x, int _y)
{
    if (_y - center_y == 1 && _x == center_x) // down line
        is_stand = (center_y - _y) % 2;

    else if (_x - center_x == 1 && _y == center_y) // right line
        is_stand = (center_x - _x) % 2;

    else if (_y == center_y && _x == 1) // left line
        is_stand = (center_x - _x) % 2;

    else if (_x == center_x && _y == 1) // up line
        is_stand = (center_y - _y) % 2;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> w >> h;
    cin >> center_x >> center_y;

    is_stand = center_y % 2;

    for (int y = 1; y <= h; y++)
    {
        for (int x = 1; x <= w; x++)
        {
            check_update_is_stand_value(x, y);

            if (x == center_x && y == center_y)
            {
                cout << "*";
            }
            else if (x == center_x || y == center_y)
            {
                // Check be stand or not
                cout << (is_stand ? "O" : "-");

                is_stand = !is_stand;
            }
            else
            {
                cout << "-";
            }
        }

        cout << endl;
    }
}