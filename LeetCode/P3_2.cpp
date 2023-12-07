#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;

    // Code
    int key = 0;
    int count = 0;
    int maxCount = 0;
    unordered_map<char, bool> data = {};

    if(s == " ") maxCount = 1;

    for (int i = 0; i < s.size(); i++)
    {
        if(data[s[i]]) // Is Same
        {
            maxCount = count > maxCount ? count : maxCount;
            while (true)
            {
                data[s[key]] = false; // The char will not to use
                if(s[key] == s[i])    // Is find the previous same char
                {
                    count = i-key; // the count from "previous same char" next char to i
                    key++;
                    data[s[i]] = true;
                    break;
                }
                key++;
            }
            cout<< endl;
        }
        else
        {
            data[s[i]] = true;
            count++;
        }
    }
    maxCount = count > maxCount ? count : maxCount;

    cout << maxCount;
}