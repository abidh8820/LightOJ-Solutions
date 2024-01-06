#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
const int N = 1 << 18, K = 20;

int a[N], st[N][K], Log[N + 1], n;


void buildTable() {
    Log[1] = 0;
    for (int i = 2; i < N; ++i) {
        Log[i] = Log[i / 2] + 1;
    }
    for (int i = 0; i < n; ++i) {
        st[i][0] = a[i];
    }
    for (int j = 1; j <= K; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int L, int R) {
    int j = Log[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}

int main() {
    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        buildTable();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            LL lo = i, hi = n, mid, L, R;

            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (query(i, mid) == a[i]) {
                    R = mid, lo = mid + 1;
                } else       hi = mid - 1;
            }

            lo = 0, hi = i;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (query(mid, i) == a[i]) {
                    L = mid, hi = mid - 1;
                } else       lo = mid + 1;
            }

            ans = max(ans, (R - L + 1) * a[i]);
        }

        cout << ans << endl;
    }
}
