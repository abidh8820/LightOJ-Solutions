#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
const int N = 1e6 + 7;
const int M = 1e9 + 7;

LL BM(LL a, LL p) {
    if (p == 0) return 1;
    if (p == 1) return a;
    if (p & 1) return (a * BM(a, p - 1)) % M;
    LL f = BM(a, p / 2);
    return (f * f) % M;
}
LL fac[N], invfac[N], dar[N];

LL C(int n, int r) {
    LL ret = fac[n];
    ret = (ret * invfac[r]) % M;
    ret = (ret * invfac[n - r]) % M;
    return ret;
}

void pre() {
    fac[0] = 1, dar[2] = 1, dar[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = (fac[i - 1] * i) % M;
    invfac[N - 1] = BM(fac[N - 1], M - 2);
    for (int i = N - 2; i >= 0; i--) invfac[i] = (invfac[i + 1] * (i + 1)) % M;
    for (int i = 3; i < N; i++) dar[i] = ((i - 1) * (dar[i - 1] + dar[i - 2]) % M) % M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    pre();
    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, m, k;
        cin >> n >> m >> k;

        LL res = C(m, k), ans = 0;
        

        for (int i = 0; i <= n - m; i++) {
            ans += (C(n - m, i) * dar[n - k - i]) % M;
            ans %= M;
        }
        cout << (ans * res) % M << endl;
    }
}