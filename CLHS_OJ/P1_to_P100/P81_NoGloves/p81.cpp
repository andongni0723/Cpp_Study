#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if(n >= 1 && n <= 3)
        cout << "春香";
    else if(n >= 4 && n <= 6)
        cout << "夏香";
    else if(n >= 7 && n <= 9)
        cout << "秋香";
    else if(n >= 10 && n <= 12)
        cout << "冬香";
    else
        cout << "石榴不要！";
}