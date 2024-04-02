#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

//vector<vector<int>> dp((int)2e5+100, vector<int>((int)2e5+100, -1));
//int dp(int i, int k)
//{
//
//}
int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    char ts;
    string ta;
    vector<bool> people((int)2e5+100, false);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> ts >> ta;
        int age = stoi(ta);
        people[i] = age >= 65 || age <= 12 || (ts == 'F' && (age >= 35 && age <= 45));
    }

//    for (int i = 0; i < n; i++)
//    {
//        cout << people[i] << endl;
//    }

    int currentFrontOld = 0;
    int change = 0;
    for (int i = 0; i < n; i++)
    {
        if(currentFrontOld >= k) break;
        if(people[i])
        {
            currentFrontOld++;
            continue;
        }
        else
        {
            for (int j = i+1; j < n - i; j++)
            {
                if(people[j] && j > k-1)
                {
                    people[i] = true;
                    people[j] = false;
                    currentFrontOld++;
                    change++;
                    break;
                }
            }
        }

    }
    cout << change;

}

//
//5 2
//1 0 1 0 1
//f(i, k) : 前i個人中, 要向前放K人的 最小交換次數
//
//f(i, k) =