#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

struct SegTree {
    int n;
    vector<LL> tr, lz;

    SegTree(){};
    SegTree(int sz) {
        n = sz;
        tr.resize(4 * n, 0);
        lz.resize(4 * n, -1);
    }

    LL combine(LL left, LL right) { 
        return left + right;
    }

    void propagate(int u, int st, int en) {
        if (lz[u]==-1) return;
        tr[u] = (en - st + 1) * lz[u];
        if (st != en) {
            lz[2 * u] = lz[u];
            lz[2 * u + 1] = lz[u];
        }
        lz[u] = -1;
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

    LL query(int u, int st, int en,int l, int r) {
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
        cout << "Case " << ++cs << ":\n";
        int n, q;
        cin >> n >> q;
        SegTree tree(n);

        while(q--){
            int type, l, r, val;
            cin >> type >> l >> r;

            if(type==1){
                cin >> val;
                tree.update(1, 0, n-1, l, r, val);
            }
            else {
                LL up = tree.query(1, 0, n-1, l, r);
                LL down = r-l+1;
                int g = __gcd(up, down);
                up /= g, down /= g;
                if(up==0 || down==1) cout << up<<"\n";
                else cout <<up<<"/"<<down<<"\n";
            }
        }
    }
}

