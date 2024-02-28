#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> vec;
    int n, q, target;

    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        vec.push_back(t);
    }

    sort(vec.begin(), vec.end());

    // Binary Search q times to find target

    for (int i = 0; i < q; i++)
    {
        cin >> target;
        int left = 0;
        int right = n - 1;
        int mid = (left + right) / 2;
        bool found = false;

        while (left <= right)
        {
            if (vec[mid] == target)
            {
                found = true;
                break;
            }
            else if (vec[mid] < target)
            {
                left = mid + 1;
            }
            else if (vec[mid] > target)
            {
                right = mid - 1;
            }
            mid = (left + right) / 2;
        }

        if (found)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
