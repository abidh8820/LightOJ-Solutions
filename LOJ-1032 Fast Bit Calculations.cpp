#include <bits/stdc++.h>
using namespace std;

using LL = long long;

LL dp[32][2][2][32];

LL recur(int pos, int prv, bool relax, int got, vector<bool>& a) {
    if (pos == a.size()) return got;

    LL& ret = dp[pos][prv][relax][got];
    if (~ret) return ret;

    ret = 0;
    int upto = a[pos];
    if (relax) upto = 1;

    for (int i = 0; i <= upto; i++) {
        ret += recur(pos + 1, i, relax | (i < a[pos]), got + (prv == 1 && i == 1), a);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        LL n;
        cin >> n;

        vector<bool> a(31);

        for (int i = 31; i >= 0; i--) {
            if (n >> i & 1) a[i] = 1;
        }

        reverse(a.begin(), a.end());
        memset(dp, -1, sizeof dp);

        cout << "Case " << ++cs << ": ";
        cout << recur(0, 0, 0, 0, a) << endl;
    }
}

