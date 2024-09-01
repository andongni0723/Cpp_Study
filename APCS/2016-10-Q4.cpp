#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";


class player
{
public:
    int hitCount;
    vector<char> hitData;

    player()
    {
        hitCount = 0;
    }
};

class hitData
{
public:
    int player; // id 1~9
    string hitCode;

    hitData(int id, string hitCode)
    {
        player = id;
        this->hitCode = hitCode;
    }
};

vector<vector<hitData>> vec(10, vector<hitData>());
vector<int> base(4, -1);
lint score = 0;

void run(int hitPlayer)
{
    if(base[3] != -1) score++;
    base[3] = base[2];
    base[2] = base[1];
    base[1] = hitPlayer;
}

void clear()
{
    base[3] = -1;
    base[2] = -1;
    base[1] = -1;
}

int main()
{
    int t, b;
    string s;
    for (int i = 1; i <= 9; i++)
    {
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            cin >> s;
            vec[j].emplace_back(i, s);
        }
    }

    cin >> b;

    bool isEnd = false;
    int outCount = 0;
    int allOutCount = 0;

    for(auto list : vec)
    {
        //(1) 安打：以1B,2B,3B和HR 分別代表一壘打、二壘打、三壘打和全（四）壘打。
        //(2)出局：以 FO, GO和 SO表示
        for (auto data : list)
        {
            if(data.hitCode == "1B")
            {
                run(data.player);
            }
            else if(data.hitCode == "2B")
            {
                run(data.player);
                run(-1);
            }
            else if(data.hitCode == "3B")
            {
                run(data.player);
                run(-1);
                run(-1);
            }
            else if(data.hitCode == "HR")
            {
                run(data.player);
                run(-1);
                run(-1);
                run(-1);
            }
            else // FO SO GO
            {
                outCount++;
                allOutCount++;
            }

            if(outCount == 3)
            {
                clear();
                outCount = 0;
            }

            if(allOutCount == b)
            {
                isEnd = true;
                break;
            }


        }
        if(isEnd) break;
    }

    cout << score;
}
