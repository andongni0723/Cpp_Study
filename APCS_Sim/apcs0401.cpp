#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);


    int n, t1, t2;
    int p_total = 0, n_total = 0;
    int p_score = 0, n_score = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;

        if(t1 > t2)
            p_score ++;
        else
            n_score++;

        p_total += t1;
        n_total += t2;
    }


    bool p_win;

    p_win = p_score > n_score;

    if(p_score == n_score)
        p_win = p_total > n_total;

    cout << (p_win ? "Positive side" : "Negative side") << endl;
    cout << p_score << " " << n_score << endl;
    cout << p_total << " " << n_total;
}