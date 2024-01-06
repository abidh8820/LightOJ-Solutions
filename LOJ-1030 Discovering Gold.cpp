#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 1e6 + 7;
double dp[N];
bool vis[N];
int a[N], n;

double call(int pos) {
    if (pos > n) return 0.0;
    if (vis[pos]) return dp[pos];

    double& ret = dp[pos];
    ret = 0.0; int cnt = 0;
    for (int i = 1; i <= 6 && pos + i <= n; i++) {
        cnt++, ret += call(pos + i);
    }

    if (cnt) ret /= cnt;
    ret += a[pos], vis[pos] = true;
    return ret;
}

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 0; i <= n; i++) dp[i] = -1, vis[i] = false;

        cout << fixed << setprecision(10) << call(1) << "\n";
    }
}

