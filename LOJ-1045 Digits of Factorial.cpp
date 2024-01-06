#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 1e6 + 7;
double csum[N];

int main() {
    int t, cs = 0;
    cin >> t;

    for (int i = 1; i < N; i++) {
        csum[i] += (csum[i - 1] + log(i));
    }

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, base;
        cin >> n >> base;

        LL ans = csum[n] / log(base);
        cout << ans + 1 << "\n";
    }
}

