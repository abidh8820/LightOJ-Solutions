#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

const LL M = 1e8 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  LL t, cs = 0;
  cin >> t;

  while (t--) {
    cout << "Case " << ++cs << ": ";

    LL n, k, s;
    cin >> n >> k >> s;

    vector<int> dp(s + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
      vector<int> new_dp(s + 1, 0);
      for (int sum = 1; sum <= s; sum++) 
        dp[sum] += dp[sum - 1], dp[sum] %= M;

      for (int sum = 1; sum <= s; sum++) {
        new_dp[sum] = dp[sum - 1];
        if (sum - k - 1 >= 0) new_dp[sum] -= dp[sum - k - 1];
        if (new_dp[sum] < 0) new_dp[sum] += M;
      }

      dp = new_dp;
    }

    cout << dp[s] << "\n";
  }
}

