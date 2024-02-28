#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    bool isPassed = false;
    vector<int> scoreVec;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int score;
        cin >> score;
        scoreVec.push_back(score);
    }

    sort(scoreVec.begin(), scoreVec.end());

    // Output
    for (auto it : scoreVec)
    {
        cout << it << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (scoreVec[i] >= 60 && !isPassed)
        {
            if (i == 0)
            {
                cout << "best case" << endl;
                cout << scoreVec[i] << endl; // first passed
            }
            else if (scoreVec[i - 1] < 60)
            {
                cout << scoreVec[i - 1] << endl; // last failed
                cout << scoreVec[i] << endl;     // first passed
            }

            isPassed = true;
        }

        if (i == n - 1 && scoreVec[i] < 60)
        {
            cout << scoreVec[i] << endl; // last failed
            cout << "worst case" << endl;
        }
    }
}
