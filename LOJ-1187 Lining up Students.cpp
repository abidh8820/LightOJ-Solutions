#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct BIT {
    int n;
    vector<int> ft;
    BIT(int n_) {
        n = n_ + 5;
        ft.assign(n, 0);
    }
    void update(int idx, int val) {
        for (idx++; idx < n; idx += idx & -idx) ft[idx] += val;
    }
    int query(int idx) {
        int sum = 0;
        for (idx++; idx > 0; idx -= idx & -idx) sum += ft[idx];
        return sum;
    }
    int query(int i, int j) {
        if (i > j) return 0;
        return query(j) - query(i - 1);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        vector<int> a(n), ans(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        BIT bit(n);
        for (int i = n; i > 0; i--) {
            int lo = 1, hi = n, res = -1;
            while (lo <= hi) {
                int mid = lo + hi >> 1;
                int got = n - mid - bit.query(mid + 1, n);
                if (got <= a[i - 1]) res = mid, hi = mid - 1;
                else lo = mid + 1;
            }

            ans[i - 1] = res;
            bit.update(res, 1);
        }

        cout << ans[0] << "\n";
    }
}

