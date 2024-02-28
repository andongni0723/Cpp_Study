#include <bits/stdc++.h>
using namespace std;
using lint = long long int;


int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, s1_a_pos = -1, s2_a_pos = -1;
    string s1, s2;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;

        // len
        if(s1.size() > s2.size())
        {
            cout << s1 << endl;
            continue;
        }
        else if(s1.size() < s2.size())
        {
            cout << s2 << endl;
            continue;
        }

        // 'A' pos
        for (int j = 0; j < s1.size(); j++)
        {
            if(s1[j] == 'A')
                s1_a_pos = j;
        }

        for (int j = 0; j < s2.size(); j++)
        {
            if(s2[j] == 'A')
                s2_a_pos = j;
        }

        if(s1_a_pos < s2_a_pos)
        {
            cout << s1 << endl;
            continue;
        }
        else if(s1_a_pos > s2_a_pos)
        {
            cout << s2 << endl;
            continue;
        }

        // char big
        bool isSame = true;
        for (int j = 0; j < s1.size(); j++)
        {
            if(s1[j] > s2[j])
            {
                cout << s1 << endl;
                isSame = false;
                break;
            }
            else if(s1[j] < s2[j])
            {
                cout << s2 << endl;
                isSame = false;
                break;
            }
        }

        if(isSame)
            cout << "AMAZING" << endl;
    }

}