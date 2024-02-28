#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    string date;
    cin >> date;
    string year = {date[0], date[1], date[2], date[3]};
    string month;
    string day;

    cout << year << "/";

    if(date[4] == 0)
        cout << date[5] << "/";
    else
    {
        month = {date[4], date[5]};
        cout << month << "/";
    }

    if(date[6] == 0)
        cout << date[7] << "/";
    else
    {
        month = {date[6], date[7]};
        cout << month;
    }
}