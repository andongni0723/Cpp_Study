#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n;
    string last_word = "-", current_word;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> current_word;
        if(last_word == "-" || last_word[last_word.size() - 1] == current_word[0])
        {
            last_word = current_word;
            cout << "ok" << endl;
        }
        else
        {
            last_word = "-";
            cout << "not ok" << endl;
        }
    }
}