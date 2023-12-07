#include <bits/stdc++.h>
using namespace std;

int GetMaxSum(vector<int> vec, int size, int k)
{
    if (k > size)
        return -1;

    int maxSum = 0;
    int currentSum = 0;

    for (int i = 0; i < k; i++)
    {
        currentSum += vec[i];
        maxSum = currentSum;
    }

    for (int i = 0; i < size - k; i++)
    {
        currentSum = currentSum - vec[i] + vec[i + k];

        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    vector<int> inputV;

    cin >> k;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        inputV.push_back(t);
    }

    cout << GetMaxSum(inputV, inputV.size(), k);
}
