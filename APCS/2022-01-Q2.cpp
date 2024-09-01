#include <bits/stdc++.h>
using namespace std;
// using lint = long long int;
#define int long long
#define endl "\n";

int n, m;

vector<int> attack(1010);
vector<int> defense(1010);
vector<int> lostTime(1010, 0);

queue<int> fightSeq;
queue<int> win;
queue<int> lose;
queue<int> other;
set<int> player;

void fight(int i, int j)
{
    int a = attack[i];
    int b = defense[i];
    int c = attack[j];
    int d = defense[j];
    if(a * b >= c * d)
    {
        attack[i] += c * d / (2 * b);
        defense[i] += c * d / (2 * a);
        attack[j] += c / 2;
        defense[j] += d / 2;

        lostTime[j]++;
        if(lostTime[j] >= m)
        {
            player.erase(j);
            win.emplace(i);
        }
        else
        {
            win.emplace(i);
            lose.emplace(j);
        }

    }
    else
    {
        attack[j] += a * b / (2 * d);
        defense[j] += a * b / (2 * c);
        attack[i] += a / 2;
        defense[i] += b / 2;

        lostTime[i]++;
        if(lostTime[i] >= m)
        {
            player.erase(i);

            win.emplace(j);
        }
        else
        {
            win.emplace(j);
            lose.emplace(i);
        }
    }
}

void sortFightSeq()
{
    while (!fightSeq.empty())
    {
        int t = fightSeq.front();
        fightSeq.pop();
        other.emplace(t);
    }

    while (!win.empty())
    {
        int t = win.front();
        win.pop();
        fightSeq.emplace(t);
    }

    while (!other.empty())
    {
        int t = other.front();
        other.pop();
        fightSeq.emplace(t);
    }

    while (!lose.empty())
    {
        int t = lose.front();
        lose.pop();
        fightSeq.emplace(t);
    }
}
signed main()
{

    cin >> n >> m;

    int t;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        attack[i] = t;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        defense[i] = t;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        fightSeq.emplace(t);
        player.insert(t);
    }

    while (player.size() != 1)
    {
        int s = fightSeq.size();
        for (int i = 0; i < s; i+=2)
        {
            if (fightSeq.size() < 2) break;
            int a = fightSeq.front();
            fightSeq.pop();
            int b = fightSeq.front();
            fightSeq.pop();
            fight(a ,b);
        }

        sortFightSeq();
    }

    cout << *player.begin();
}
