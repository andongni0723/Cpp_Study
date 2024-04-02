#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

class ChangePlayer
{
public:
    int time;
    int downPlayer;
    int upPlayer;
    
    ChangePlayer(int time, int downPlayer, int upPlayer)
    {
        this->time = time;
        this->downPlayer = downPlayer;
        this->upPlayer = upPlayer;
    }
};

bool comp(ChangePlayer a, ChangePlayer b)
{
    return b.time > a.time;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> player;
    vector<ChangePlayer> changePlayerEvent;
    vector<int> outPlayerEvent;
    int n, q, t, m, s, dp, up;
    int changeEventPointer = 0;
    cin >> n >> q;

    for (int i = 0; i < 11; i++)
    {
        cin >> t;
        player.push(t);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> m >> s >> dp >> up;
        changePlayerEvent.emplace_back(ChangePlayer(m * 60 + s, dp, up));
    }

    for (int i = 0; i < q; i++)
    {
        cin >> m >> s;
        outPlayerEvent.emplace_back(m * 60 + s);
    }

    sort(changePlayerEvent.begin(), changePlayerEvent.end(), comp);

    // main
    for (int i = 0; i < q; i++)
    {
        queue<int> newPlayer = player;
        changeEventPointer = 0;

        while(outPlayerEvent[i] >= changePlayerEvent[changeEventPointer].time)
        {
            // find player index about down number
            for (int j = 0; j < 11; j++)
            {
                int currentPlayer = newPlayer.front();
                newPlayer.pop();
                if(currentPlayer == changePlayerEvent[changeEventPointer].downPlayer)
                    newPlayer.push(changePlayerEvent[changeEventPointer].upPlayer);
                else
                    newPlayer.push(currentPlayer);
            }

            changeEventPointer++;

            if(changeEventPointer >= changePlayerEvent.size())
                break;
        }

        for (int j = 0; j < 11; j++)
        {

            cout << newPlayer.front();
            newPlayer.pop();

            if(j != 10)
                cout << " ";
            else
                cout << endl;
        }
    }
}