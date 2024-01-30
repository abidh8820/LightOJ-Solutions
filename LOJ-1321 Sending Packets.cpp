#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0;
  cin >> t;

  while (t--) {
    cout << "Case " << ++cs << ": ";
    int n, m, s, k;
    cin >> n >> m >> s >> k;

    vector<vector<double>> dp(n, vector<double>(n, 0.0));

    for (int i = 0; i < m; i++) {
      int u, v, p;
      cin >> u >> v >> p;
      dp[u][v] = dp[v][u] = 1.0 * p / 100;
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dp[i][j] = max(dp[i][j], dp[i][k] * dp[k][j]);
        }
      }
    }

    cout << fixed << setprecision(10) << 2.0 * s * k / dp[0][n - 1] << "\n";
  }
}

