#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "bugprone-branch-clone"
#include <bits/stdc++.h>
using namespace std;

int w, h;                 // the all seat width, height
int center1_x, center1_y; // the center seat of 1st input position
int center2_x, center2_y; // the center seat of 2nd input position
int x = 0, y = 0;         // current printing seat position
int is_stand1 = 0;        // bool (1.txt.out: stand , 0: not stand)
int is_stand2 = 0;        // bool (1.txt.out: stand , 0: not stand)

/// @brief According to center position to
// calc the "big plus" first people in line be standing or not
void check_update_is_stand_value(int _x, int _y, int *center_x, int *center_y, int *is_stand)
{
    if (_y - *center_y == 1 && _x == *center_x) // down line
        *is_stand = (*center_y - _y) % 2;

    else if (_x - *center_x == 1 && _y == *center_y) // right line
        *is_stand = (*center_x - _x) % 2;

    else if (_y == *center_y && _x == 1) // left line
        *is_stand = (*center_x - _x) % 2;

    else if (_x == *center_x && _y == 1) // up line
        *is_stand = (*center_y - _y) % 2;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

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

            // Update stand value
            check_update_is_stand_value(x, y, &center1_x, &center1_y, &is_stand1);
            check_update_is_stand_value(x, y, &center2_x, &center2_y, &is_stand2);

            if (x == center1_x && y == center1_y || // is line center
                x == center2_x && y == center2_y)
            {
                cout << "*";
            }
            else if (in_line1 || in_line2) // in line 1.txt.out or line2
            {
                if (in_line1 && in_line2) // in line 1.txt.out and line2
                {
                    cout << "#";

                    is_stand1 = !is_stand1;
                    is_stand2 = !is_stand2;
                }
                else if (in_line1) // in line 1.txt.out
                {
                    // Check be stand or not
                    cout << (is_stand1 ? "O" : "-");
                    is_stand1 = !is_stand1;
                }
                else if (in_line2) // in line 2
                {
                    // Check be stand or not
                    cout << (is_stand2 ? "O" : "-");
                    is_stand2 = !is_stand2;
                }
            }
            else
            {
                cout << "-";
            }
        }

        cout << endl;
    }
}
#pragma clang diagnostic pop