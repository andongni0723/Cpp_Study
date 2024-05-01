#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, machine_count, t;
    const int MAX = (int)1e8+10;
    multiset<int> current_machine;
    vector<pair<int, int>> end_start_event; // end, start

    // input
    cin >> n >> machine_count;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        end_start_event.emplace_back(0, t);
    }
    for (int i = 0; i < n; i++)
        cin >> end_start_event[i].first;

    current_machine.insert(-2); // left boundary
    current_machine.insert(MAX); // right boundary
    for (int i = 0; i < machine_count; i++)
    {
        current_machine.insert(-1); // initial
    }

    // main
    lint result = 0;
    sort(end_start_event.begin(), end_start_event.end()); // end small to big
    for (int i = 0; i < n; i++)
    {
        auto iter = current_machine.lower_bound(end_start_event[i].second);

        if(iter != current_machine.end()) // not find
        {
            // 最靠近current event start 的 event end
           auto prev_iter = prev(iter);

           // touch left bound or current event start equal past event end
           if(*prev_iter == -2 || *prev_iter == end_start_event[i].second) continue;

           // change event end
           current_machine.erase(current_machine.find(*prev(iter)));
           current_machine.insert(end_start_event[i].first);
           result++;
        }
    }

    cout << result;
}