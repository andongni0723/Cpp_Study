#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    bool isStart;
    string n;
    int count = 0;
    cin >> n;

    string current;
    for (int i = 0; i < n.size(); i++)
    {
        current += n[i];

        if(!isStart && current.size() == 3)
        {
            if(current == "AUG")
            {
                count++;
                isStart = true;
                current = "";
            }
        }
        else if(isStart && current.size() == 3)
        {
            if(current == "UAA" || current == "UAG" || current == "UGA")
            {
                isStart = false;
                break;
            }
            else
            {
                count++;
                current = "";
            }
        }
        else if(!isStart)
        {
            if(current.size() > 1) continue;
            if(current == "A") continue;
            current = "";
        }


    }

    cout << count;

}