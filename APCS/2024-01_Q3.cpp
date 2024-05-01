#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

class gate
{
public:
    int type; // -1 : input | -2: output | 1: and | 2: or | 3: xor | 4: not
    int indeg;
    int input1;
    int input2;
    int output;
    int delay;
};

vector<vector<int>> graph((int)1e6, vector<int>());
vector<gate> gates((int)1e6, gate());
queue<int> que;

void topo()
{
    while(!que.empty())
    {
        int currentGate = que.front(); que.pop();

        for (int i = 0; i < graph[currentGate].size(); i++)
        {
            int childID = graph[currentGate][i];
            gate &child = gates[childID];

            if(child.type == 1 ||
            child.type == 2 ||
            child.type == 3) // and or xor
            {
                if(child.indeg == 2)
                {
                    child.input1 = gates[currentGate].output;
                    child.delay = max(child.delay, gates[currentGate].delay + 1);
                    child.indeg--;
                }
                else if(child.indeg == 1)
                {
                    child.input2 = gates[currentGate].output;
                    child.delay = max(child.delay, gates[currentGate].delay + 1);
                    child.indeg--;

                    // calc logic
                    if(child.type == 1) //and
                        child.output = child.input1 & child.input2;
                    else if(child.type == 2) // or
                        child.output = child.input1 | child.input2;
                    else if(child.type == 3) // xor
                        child.output = child.input1 ^ child.input2;

                    que.push(childID);
                }
            }
            else if(child.type == 4) // not
            {
                if(child.indeg == 1)
                {
                    child.input1 = gates[currentGate].output;
                    child.delay = max(child.delay, gates[currentGate].delay + 1);
                    child.indeg--;

                    child.output = !child.input1;

                    que.push(childID);
                }
            }
            else if(child.type == -2) // output
            {
                child.input1 = gates[currentGate].output;
                child.delay = gates[currentGate].delay;
                child.output = child.input1;

                child.indeg--;
            }
        }
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int p, q, r, m, t, t1;
    cin >> p >> q >> r >> m;

    // INPUT
    for (int i = 1; i <= p; i++) //input
    {
        cin >> t;
        gates[i].type = -1;
        gates[i].output = t;
    }
    for(int i = 1; i <= q; i++) //logic
    {
        cin >> t;
        gates[p + i].type = t;
    }
    for(int i = 1; i <= r; i++) //output
    {
        gates[p + q + i].type = -2;
    }
    for(int i = 0; i < m; i++) //line
    {
        cin >> t >> t1;
        graph[t].emplace_back(t1);
        gates[t1].indeg++;
    }

    // put input node in queue (topo-sort prepare)
    for(int i = 1; i <= p; i++) que.push(i);

    topo();

    int maxDelay = 0;
    for (int i = 1; i <= r; i++) // get max delay
    {
        maxDelay = max(maxDelay, gates[p + q + i].delay);
    }

    cout << maxDelay << endl;

    for (int i = 1; i <= r; i++) // output output gate
    {
        cout << gates[p + q + i].output << " ";
    }
}