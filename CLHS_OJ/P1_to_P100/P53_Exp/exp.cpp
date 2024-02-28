#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    long long inputXP, calXP, sumLvMaxXP = 10, currentLv = 1;
    bool isOn = true;

    // Input
    cin >> inputXP;

    // Calc
    while (isOn)
    {
        if (inputXP >= sumLvMaxXP)
        {
            currentLv++;
            sumLvMaxXP += currentLv * 10;
        }
        else
        {
            break;
        }
    }

    calXP = inputXP - (sumLvMaxXP - currentLv * 10);

    // Output
    cout << currentLv << " " << calXP << endl;
}
