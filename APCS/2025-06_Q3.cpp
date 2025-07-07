// q838. 3. 貪心闖關
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
using Node = pair<ll, int>;

int n, t;
vector<int> next_bag(4*1e5); // one-base
int find_next(int x)
{
    if (x > n) return n+1;
    if (x == next_bag[x]) return x;
    return next_bag[x] = find_next(next_bag[x]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // one-base
    vector<ll> vec(4*1e5, 0);
    priority_queue<Node, vector<Node>, greater<>> pq; // bagCount, idx

    cin >> n >> t;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> vec[i];
        next_bag[i] = i;
        pq.emplace(vec[i], i);
    }
    next_bag[n+1] = n+1;

    ll result = 0;
    while(!pq.empty())
    {
        auto top = pq.top(); pq.pop();
        auto bags = top.first;
        auto idx = top.second;

        if(vec[idx] != bags) continue; // old data
        if(bags > t) break; // heavy

        int next_idx = find_next(idx + 1);
        result += bags;
        vec[idx] = 0;
        next_bag[idx] = next_idx;

        if(next_idx == n+1) continue; // is last

        vec[next_idx] += bags;
        pq.emplace(vec[next_idx], next_idx);
    }

    cout << result;
}

/*
void print_debug(vector<ll>& v)
{
    for(int i = 1 ; i <= n ; i++)
        cout << v[i] << " " ;
    cout << endl;
}

void print_nb(vector<int>& v)
{
    for(int i = 1 ; i <= n ; i++)
        cout << v[i] << " " ;
    cout << endl;
}
*/

/*
r++;
if(r >= 10)
{
    cout << "inf while";
    break;
}
auto minBag = *mset.begin();
cout << "---" << endl;
cout << minBag.first << " " << minBag.second << endl;

if(minBag.first <= t)
{
    // cout << "0" << " ";
    mset.erase(mset.begin());
    // cout << "1" << " ";

    cout << vec[next_bag[minBag.second]-1] << " " << minBag.second+1 << endl;
    auto it = mset.find(make_pair(vec[next_bag[minBag.second]-1], minBag.second+1));
    // cout << "2" << " ";
    mset.insert(make_pair(it->first + minBag.first, it->second)); // to next bag
    // cout << "3" << " ";
    mset.erase(it);
    // cout << "4" << " ";
    vec[minBag.second-1] = 0;
    vec[minBag.second] += minBag.first;



    next_bag[minBag.second] = next_bag[minBag.second+1];
    result += minBag.first;

    print_debug(vec);
    print_nb(next_bag);
}
else break;
*/