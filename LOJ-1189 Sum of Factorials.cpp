#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 21;
LL fac[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i;

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        LL n;
        cin >> n;

        vector<int> ans;

        for (int i = N - 1; i >= 0; i--) {
            if (n >= fac[i]) {
                n -= fac[i];
                ans.push_back(i);
            }
        }

        if (n != 0) {
            cout << "impossible\n";
            continue;
        }

        sort(ans.begin(), ans.end());
        int m = ans.size();
        for (int i = 0; i < m; i++) cout << ans[i] << "!" << "+\n"[i + 1 == m];
    }
}

