#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
const int N = 1 << 18;

LL tree[N * 4], prob[N * 4], a[N];

void build(int u, int l, int r) {
    if (l == r) {
        tree[u] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    tree[u] = min(tree[u * 2], tree[u * 2 + 1]);
}

LL query(int u, int l, int r, int i, int j) {
    if (l > j || r < i) return 1e18;
    if (l >= i && r <= j) return tree[u];
    int mid = (l + r) / 2;
    return min(query(u * 2, l, mid, i, j), query(u * 2 + 1, mid + 1, r, i, j));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":" << endl;
        int n, q;
        cin >> n >> q;

        for (int i = 1; i <= n; i++) cin >> a[i];
        build(1, 1, n);

        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
}
