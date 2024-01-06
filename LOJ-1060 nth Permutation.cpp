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
        string s;
        cin >> s;

        int n = s.size(), k;
        cin >> k;

        map<char, int> mp;
        for (int i = 0; i < n; i++) mp[s[i]]++;
        LL tot = fac[n];

        for (auto [x, y] : mp) tot /= fac[y];

        if (k > tot) {
            cout << "Impossible\n";
            continue;
        }

        LL got = 0;
        string ans = "";

        for (int pos = 0; pos < n; pos++) {
            char g = '#';
            for (auto& [nxt, cnt] : mp) {
                if (cnt == 0) continue;
                g = nxt;
                LL now = fac[n - pos - 1];
                LL need = k - got;

                for (auto [x, y] : mp) {
                    if (x == nxt) now /= fac[(y - 1)];
                    else now /= fac[y];
                }

                if (now >= need) {
                    ans += nxt, g = nxt;
                    break;
                }
                got += now;
            }
            if (g != '#') mp[g]--;
        }

        cout << ans << endl;
    }
}

