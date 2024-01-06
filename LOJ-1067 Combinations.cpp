#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 1e6 + 2;
const int M = 1000003;
LL fac[N], invfac[N];

LL BM(LL a, LL p) {
    if (p == 0) return 1;
    if (p == 1) return a;
    if (p & 1) return (a * BM(a, p - 1)) % M;
    LL f = BM(a, p / 2);
    return (f * f) % M;
}

void pre() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = (fac[i - 1] * i) % M;
    invfac[N - 1] = BM(fac[N - 1], M - 2);
    for (int i = N - 2; i >= 0; i--) invfac[i] = (invfac[i + 1] * (i + 1)) % M;
}

LL C(int n, int r) {
    if (!fac[0]) pre();
    if (r > n) return 0;
    LL ret = fac[n];
    ret = (ret * invfac[r]) % M;
    ret = (ret * invfac[n - r]) % M;
    return ret;
}

int main() {
    int t, cs = 0;
    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, k;
        cin >> n >> k;
        cout << C(n, k) << endl;
    }
}

