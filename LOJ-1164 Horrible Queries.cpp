
#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e5 + 7;
int a[N];
LL tr[4 * N];
LL lz[4 * N];

/// 1. Merge left and right
LL combine(LL left, LL right) { return left + right; }

/// 2. Push lazy down and merge lazy
void propagate(int u, int st, int en) {
    if (!lz[u]) return;
    tr[u] += (en - st + 1) * lz[u];
    if (st != en) {
        lz[2 * u] += lz[u];
        lz[2 * u + 1] += lz[u];
    }
    lz[u] = 0;
}

void build(int u, int st, int en) {
    if (st == en) {
        tr[u] = a[st];  /// 3. Initialize
        lz[u] = 0;
        return;
    }
    int mid = (st + en) / 2;
    build(2 * u, st, mid);
    build(2 * u + 1, mid + 1, en);
    tr[u] = combine(tr[2 * u], tr[2 * u + 1]);
    lz[u] = 0;  /// 3. Initialize
}

void update(int u, int st, int en, int l, int r, int x) {
    propagate(u, st, en);
    if (r < st || en < l) return;
    if (l <= st && en <= r) {
        lz[u] += x;  /// 4. Merge lazy
        propagate(u, st, en);
        return;
    }
    int mid = (st + en) / 2;
    update(2 * u, st, mid, l, r, x);
    update(2 * u + 1, mid + 1, en, l, r, x);
    tr[u] = combine(tr[2 * u], tr[2 * u + 1]);
}

LL query(int u, int st, int en, int l, int r) {
    propagate(u, st, en);
    if (r < st || en < l) return 0;  /// 5. Proper null value
    if (l <= st && en <= r) return tr[u];
    int mid = (st + en) / 2;
    return combine(query(2 * u, st, mid, l, r), query(2 * u + 1, mid + 1, en, l, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";
        int n, q;
        cin >> n >> q;

        for (int i = 0; i < 4 * n; i++) tr[i] = 0, lz[i] = 0;

        while (q--) {
            int type;
            cin >> type;

            if (!type) {
                int x, y, v;
                cin >> x >> y >> v;

                update(1, 0, n - 1, x, y, v);
            } else {
                int l, r;
                cin >> l >> r;

                cout << query(1, 0, n - 1, l, r) << "\n";
            }
        }
    }
}

