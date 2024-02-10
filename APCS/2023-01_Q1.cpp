#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, time, score;
    int all_error_time = 0;
    int max_score = -1;
    int max_score_time = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> time >> score;

        if(score == -1)
            all_error_time++;

        if(score > max_score)
        {
            max_score = score;
            max_score_time = time;
        }
    }

    int sum = (max_score - n - all_error_time * 2) < 0 ? 0 : max_score - n - all_error_time * 2;

    cout << sum << " " << max_score_time;

}