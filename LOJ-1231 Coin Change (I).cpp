#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int M = 100000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, k;
        cin >> n >> k;

        vector<int> val(n + 1), cnt(n + 1);
        for (int i = 1; i <= n; i++) cin >> val[i];
        for (int i = 1; i <= n; i++) cin >> cnt[i];

        vector<LL> dp(k + 1);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int sum = k; sum >= 1; sum--) {
                for (int j = 1; j <= cnt[i]; j++) {
                    if (j * val[i] <= sum) dp[sum] += dp[sum - j * val[i]];
                    else break;
                    if(dp[sum] >= M) dp[sum] -= M;
                }
            }
        }

        cout << dp[k]<<"\n";
    }
}

