#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 1005;
double dp[N][N];

int vis[N][N];
int t, cs = 0;

double C2(int n) { return 1.0 * n * (n - 1) / 2; }

double call(int tiger, int deer) {
  if (tiger == 0) return 1.0;
  if (deer == 0 && tiger == 1) return 0.0;
  if (tiger < 0 or deer < 0) return 1;

  if (vis[tiger][deer]) return dp[tiger][deer];
  vis[tiger][deer] = 1;

  double tot = tiger * deer + tiger + deer + C2(tiger) + C2(deer);
  double& ret = dp[tiger][deer];

  double p_tiger_tiger = C2(tiger) / tot, p_deer_deer = C2(deer) / tot;
  double p_me_deer = deer / tot, p_tiger_deer = tiger * deer / tot;

  double f1 = 0, f2 = 0;

  f1 = p_tiger_tiger * call(tiger - 2, deer) + p_tiger_deer * call(tiger, deer - 1);
  f1 /= (1.0 - p_deer_deer - p_me_deer);

  f2 = p_tiger_tiger * call(tiger - 2, deer) + p_tiger_deer * call(tiger, deer - 1) + p_me_deer * call(tiger, deer - 1);
  f2 /= (1.0 - p_deer_deer);

  ret = max(f1, f2);
  return ret;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;

  while (t--) {
    cout << "Case " << ++cs << ": ";

    int tiger, deer;
    cin >> tiger >> deer;

    cout << fixed << setprecision(10) << call(tiger, deer) << "\n";
  }
}

