#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct SegTree {
    int n;
    vector<LL> tr, lz;

    SegTree(){};
    SegTree(int sz) {
        n = sz;
        tr.resize(4 * n, 0);
        lz.resize(4 * n, 0);
    }
    LL combine(LL left, LL right) { return left + right; }

    void propagate(int u, int st, int en) {
        if (!lz[u]) return;
        tr[u] = (en - st + 1) * lz[u];
        if (st != en) {
            lz[2 * u] = lz[u];
            lz[2 * u + 1] = lz[u];
        }
        lz[u] = 0;
    }

    void update(int u, int st, int en, int l, int r, int x) {
        propagate(u, st, en);
        if (r < st || en < l) return;
        if (l <= st && en <= r) {
            lz[u] = x;
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
        if (r < st || en < l) return 0;
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
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        SegTree tree(2 * n+5);
        for (int i = 1; i <= n; i++) {
            int l, r; cin >> l >> r;
            tree.update(1, 1, 2 * n, l, r, i);
        }

        set<LL> st;
        for(int i=1; i<=2*n; i++) st.insert(tree.query(1, 1, 2*n, i, i));

        if(st.count(0)) st.erase(0);
        cout << st.size()<<"\n";
    }
}

