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

        int cur = 1;
        LL ans = 0;
        while (cur <= n) {
            int l = n / (cur + 1) + 1;
            int r = n / cur;
            ans += 1LL * (r - l + 1) * cur;
            if (l == 1) break;
            cur = n / (l - 1);
        }

        cout << ans << "\n";
    }
}

