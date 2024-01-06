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

        map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x; mp[x]++;
        }

        bool ok = true;
        for (int i = 1; i <= n / 2; i++) {
            int cnt = mp[i - 1] + mp[n - i];
            if (cnt != 2) ok = false;
        }

        if (n & 1) {
            int i = n/2 + 1;
            int cnt = mp[i - 1] + mp[n - i]*(i-1 != n-i);
            if (cnt != 1) ok = false;
        }

        cout << (ok ? "yes" : "no") << "\n";
    }
}

