#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    srand((unsigned) time(nullptr));

    int n = 1 + (rand() % 10);
    int q = 1 + (rand() % 100);
    int sum = 0;

    cout << n << " " << q << endl;

    for (int i = 0; i < n; i++)
    {
        int ai = rand() % 100;
        sum += ai;
        cout << ai << " ";
    }
    cout << endl;

    for (int i = 0; i < q; i++)
    {
        int b = rand() % (sum * 2);
        sum = b < sum ? sum + b : sum;
        cout << b << endl;
    }
}
