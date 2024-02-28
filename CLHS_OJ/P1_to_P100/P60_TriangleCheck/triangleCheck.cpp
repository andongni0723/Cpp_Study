#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> vec;
    for (int i = 0; i < 3; i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    // Check triangle type
    if (vec[0] + vec[1] <= vec[2])
    {
        cout << "No" << endl;
    }
    else if (vec[0] * vec[0] + vec[1] * vec[1] == vec[2] * vec[2])
    {
        cout << "Right" << endl;
    }
    else if (vec[0] * vec[0] + vec[1] * vec[1] > vec[2] * vec[2])
    {
        cout << "Acute" << endl;
    }
    else if (vec[0] * vec[0] + vec[1] * vec[1] < vec[2] * vec[2])
    {
        cout << "Obtuse" << endl;
    }
}
