#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 7;

double prob[N];
int amount[N];
double dp[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        memset(dp, 0, sizeof dp);
        memset(amount, 0, sizeof amount);
        memset(prob, 0, sizeof prob);

        double p;
        int n;

        cin >> p >> n;

        dp[0] = 1.0;

        int s = 0;
        for (int i = 1; i <= n; i++) {
            cin >> amount[i] >> prob[i];
            s += amount[i];
        }

        for (int i = 1; i <= n; i++) {
            for (int sum = s; sum >= 1; sum--) {
                if (sum - amount[i]>=0) dp[sum] = max(dp[sum], dp[sum - amount[i]] * (1.0 - prob[i]));
            }
        }

        int ans = 0;
        for (int i = 0; i <= s; i++) {
            if (1.0 - dp[i] <= p) ans = i;
        }
        cout << ans << endl;
    }
}

