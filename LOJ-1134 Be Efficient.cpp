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
        int n, m;
        cin >> n >> m;

        vector<int> a(n + 1), cnt(m);
        for (int i = 1; i <= n; i++) cin >> a[i];

        LL ans = 0;
        cnt[0] = 1;

        for (int i = 1; i <= n; i++) {
            a[i] = (a[i] + a[i - 1]) % m;
            ans += cnt[a[i]], cnt[a[i]]++;
        }

        cout << ans << "\n";
    }
}

