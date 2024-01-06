#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename VT>
struct segtree {
    using DT = typename VT::DT;
    using LT = typename VT::LT;

    int L, R;
    vector<VT> tr;
    segtree(int n) : L(0), R(n - 1), tr(n << 2) {}
    segtree(int l, int r) : L(l), R(r), tr((r - l + 1) << 2) {}

    void propagate(int l, int r, int u) {
        if (l == r) return;
        VT ::apply(tr[u << 1], tr[u].lz, l, (l + r) >> 1);
        VT ::apply(tr[u << 1 | 1], tr[u].lz, (l + r + 2) >> 1, r);
        tr[u].lz = VT ::None;
    }

    void build(int l, int r, vector<DT> &v, int u = 1) {
        if (l == r) {
            tr[u].val = v[l];
            return;
        }
        int m = (l + r) >> 1, lft = u << 1, ryt = u << 1 | 1;
        build(l, m, v, lft);
        build(m + 1, r, v, ryt);
        tr[u].val = VT ::merge(tr[lft].val, tr[ryt].val, l, r);
    }

    void update(int ql, int qr, LT up, int l, int r, int u = 1) {
        if (ql > qr) return;
        if (ql == l and qr == r) {
            VT ::apply(tr[u], up, l, r);
            return;
        }
        propagate(l, r, u);
        int m = (l + r) >> 1, lft = u << 1, ryt = u << 1 | 1;
        update(ql, min(m, qr), up, l, m, lft);
        update(max(ql, m + 1), qr, up, m + 1, r, ryt);
        tr[u].val = VT ::merge(tr[lft].val, tr[ryt].val, l, r);
    }

    DT query(int ql, int qr, int l, int r, int u = 1) {
        if (ql > qr) return VT::I;
        if (l == ql and r == qr) return tr[u].val;
        propagate(l, r, u);
        int m = (l + r) >> 1, lft = u << 1, ryt = u << 1 | 1;
        DT ansl = query(ql, min(m, qr), l, m, lft);
        DT ansr = query(max(ql, m + 1), qr, m + 1, r, ryt);
        return tr[u].merge(ansl, ansr, l, r);
    }

    void build(vector<DT> &v) { build(L, R, v); }
    void update(int ql, int qr, LT U) { update(ql, qr, U, L, R); }
    DT query(int ql, int qr) { return query(ql, qr, L, R); }
};

struct add_sum {
    using DT = LL;
    using LT = LL;

    DT val;
    LT lz;

    static constexpr DT I = 0;
    static constexpr LT None = 1e7;

    add_sum(DT _val = I, LT _lz = None) : val(_val), lz(_lz) {}
    static void apply(add_sum &u, const LT &up, int l, int r) {
        if (up == None) return;
        u.val = (r - l + 1) * up;
        u.lz = up;
    }
    static DT merge(const DT &a, const DT &b, int l, int r) { return a + b; }
};

const int N = 3e5 + 7, K = 20;
vector<int> adj[N];
int st[N], en[N], timer;

int anc[N][K];
int level[N];

void dfs(int u, int par) {
    st[u] = ++timer;
    level[u] = level[par] + 1;
    anc[u][0] = par;
    for (int k = 1; k < K; k++) anc[u][k] = anc[anc[u][k - 1]][k - 1];
    for (int v : adj[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
    en[u] = ++timer;
}

int lca(int u, int v) {
    if (level[u] > level[v]) swap(u, v);
    for (int k = K - 1; k >= 0; k--)
        if (level[u] + (1 << k) <= level[v]) v = anc[v][k];

    if (u == v) return u;
    for (int k = K - 1; k >= 0; k--)
        if (anc[u][k] != anc[v][k]) u = anc[u][k], v = anc[v][k];
    return anc[u][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";
        int n; cin >> n;
        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) adj[i].clear();

        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v; u++, v++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        timer = 0, dfs(1, 0);

        vector<LL> v(n * 2 + 3, 0);
        for (int i = 1; i <= n; i++) {
            v[st[i]] = a[i], v[en[i]] = -a[i];
        }

        segtree<add_sum> tree(1, 2 * n);
        tree.build(v); int q; cin >> q;

        while (q--) {
            int type;
            cin >> type;

            if (type == 0) {
                int u, v; cin >> u >> v; u++, v++;
                if (st[u] > st[v]) swap(u, v);
                int g = lca(u, v);

                LL sum = tree.query(st[1], st[u]);
                sum += tree.query(st[1], st[v]);

                sum -= 2 * tree.query(st[1], st[g]);
                sum += tree.query(st[g], st[g]);

                cout << sum << "\n";
            } else {
                int x, val; cin >> x >> val; x++;
                tree.update(st[x], st[x], val);
                tree.update(en[x], en[x], -val);
            }
        }
    }
}

