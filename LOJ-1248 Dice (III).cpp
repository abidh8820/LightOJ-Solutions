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
        int n;
        cin >> n;

        vector<double> ans(n + 1);
        ans[0] = 0;

        for (int k = 1; k <= n; k++) {
            double p = 1.0 * k / n;
            double p_ = 1.0 - p;

            ans[k] = p * ans[k - 1] + p + p_;
            ans[k] /= p;
        }

        cout << fixed << setprecision(8);
        cout << ans[n] << "\n";
    }
}

