#include <bits/stdc++.h>
#include <vector>
using namespace std;
using lint = long long int;
#define endl "\n";

int n, t;
vector<int> vec;
vector<vector<int>> dp((int)1e3 + 10, vector<int>((int)1e3 + 10, -1));
vector<int> prefix;

// 區間[i, j]的最小花費
int f(int i, int j) {
  if (dp[i][j] != -1)
    return dp[i][j];
  if (i == j)
    return 0;
  if (i + 1 == j)
    return abs(vec[i] - vec[j]);

  int result = 9999999;
  for (int k = i; k < j; k++) {
    result = min(result, f(i, k) + f(k + 1, j) +
                             abs((prefix[i] - prefix[k + 1]) -
                                 (prefix[k + 1] - prefix[j + 1])));
  }

  dp[i][j] = result;
  return dp[i][j];
}

int main() {
  cout.sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    vec.emplace_back(t);
  }

  prefix.emplace_back(0);
  for (int i = 0; i < n; i++) {
    prefix.emplace_back(prefix[i] + vec[i]);
  }

  cout << f(0, n - 1);
}
