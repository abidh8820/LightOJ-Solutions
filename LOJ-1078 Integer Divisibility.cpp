#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        int mod, mul;
        cin >> mod >> mul;

        int cur = 0, ans = 0;
        do {
            cur = (mul + cur * 10) % mod;
            ans++;
        } while (cur);

        cout << ans << endl;
    }
}

