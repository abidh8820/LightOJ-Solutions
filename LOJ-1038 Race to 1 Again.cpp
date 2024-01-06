#include "bits/stdc++.h"
using namespace std;

const int N = 1e6 + 7;
double dp[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < N; i++) {
        if (i > 1) dp[i] += cnt[i] + 1;
        if (i > 1) dp[i] /= 1.0 * (cnt[i]);
        for (int j = 2 * i; j < N; j += i) {
            dp[j] += dp[i], cnt[j]++;
        }
    }

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n;   cin >> n;

        cout << fixed << setprecision(10);
        cout << dp[n] << endl;
    }
}