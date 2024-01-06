#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

using VI = vector<int>;

struct SegTree {
    int n;
    vector<vector<int>> tr;
    vector<LL> lz;

    SegTree(){};
    SegTree(int sz) {
        n = sz;
        tr.resize(4 * n, vector<int>(3));
        lz.resize(4 * n, 0);
    }

    VI combine(const VI& left, const VI& right) {
        VI ret(3);
        for (int i = 0; i < 3; i++) ret[i] = (left[i] + right[i]);
        return ret;
    }

    void shift(VI& v, int k) {
        VI temp(3);
        for (int i = 0; i < 3; i++) 
            temp[(i + k) % 3] = v[i];
        v = temp;
    }

    void propagate(int u, int st, int en) {
        if (!lz[u]) return;
        shift(tr[u], lz[u] % 3);

        if (st != en) {
            (lz[2 * u] += lz[u]) %= 3;
            (lz[2 * u + 1] += lz[u]) %= 3;
        }
        lz[u] = 0;
    }

    void build(int u, int st, int en) {
        if (st == en) {
            tr[u] = {1, 0, 0}, lz[u] = 0;
            return;
        }
        int mid = (st + en) / 2;
        build(2 * u, st, mid);
        build(2 * u + 1, mid + 1, en);
        tr[u] = combine(tr[2 * u], tr[2 * u + 1]);
        lz[u] = 0;
    }

    void update(int u, int st, int en, int l, int r, int x) {
        propagate(u, st, en);
        if (r < st || en < l) return;

        if (l <= st && en <= r) {
            lz[u] += x, lz[u] %= 3;
            propagate(u, st, en);
            return;
        }

        int mid = (st + en) / 2;
        update(2 * u, st, mid, l, r, x);
        update(2 * u + 1, mid + 1, en, l, r, x);
        tr[u] = combine(tr[2 * u], tr[2 * u + 1]);
    }

    VI query(int u, int st, int en, int l, int r) {
        propagate(u, st, en);
        if (r < st || en < l) return {0, 0, 0};
        if (l <= st && en <= r) return tr[u];
        int mid = (st + en) / 2;
        return combine(query(2 * u, st, mid, l, r), query(2 * u + 1, mid + 1, en, l, r));
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";
        int n, q;
        cin >> n >> q;

        SegTree tree(n);
        tree.build(1, 0, n - 1);

        for (int i = 0; i < q; i++) {
            int type;
            cin >> type;

            if (type == 0) {
                int l, r; cin >> l >> r;
                tree.update(1, 0, n - 1, l, r, 1);
            } 
            else {
                int l, r; cin >> l >> r;
                VI ans = tree.query(1, 0, n - 1, l, r);
                cout << ans[0] << "\n";
            }
        }
    }
}

