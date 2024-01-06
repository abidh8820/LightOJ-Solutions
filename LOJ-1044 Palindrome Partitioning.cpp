#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 1007;
bool is_pal[N][N];
int dp[N];

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";

        memset(is_pal, 0, sizeof is_pal);
        memset(dp, 0x0b, sizeof dp);

        string s;
        cin >> s;

        int n = s.size();

        for (int i = 0; i < n; i++) is_pal[i][i] = true;
        for (int i = 0; i + 1 < n; i++) is_pal[i][i + 1] = (s[i] == s[i + 1]);

        for (int len = 3; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                is_pal[l][r] = (is_pal[l + 1][r - 1] && s[l] == s[r]);
            }
        }

        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (is_pal[j][i]) {
                    int cur = 1;
                    if (j > 0) cur += dp[j - 1];
                    dp[i] = min(dp[i], cur);
                }
            }
        }

        cout << dp[n - 1] << "\n";
    }
}

