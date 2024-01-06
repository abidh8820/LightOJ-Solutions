#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

struct BIT {
    int n;
    vector<int> ft;
    BIT(int n_) {
        n = n_ + 5;
        ft.resize(n + 5, 0);
    }
    void update(int idx, int val) {
        while (idx <= n) ft[idx] += val, idx += idx & (-idx);
    }
    int query(int idx) {
        int sum = 0;
        while (idx > 0) sum += ft[idx], idx -= idx & (-idx);
        return sum;
    }
    int query(int i, int j) { return query(j) - query(i - 1); }
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

        BIT ft(n);

        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            ft.update(i, x);
        }

        while (q--) {
            int type;
            cin >> type;

            if (type == 1) {
                int x; cin >> x; x++;
                int got = ft.query(x, x);
                cout << got << "\n";
                ft.update(x, -got);
            } 
            else if (type == 2) {
                int idx, val;
                cin >> idx >> val; idx++;
                ft.update(idx, val);
            } else {
                int l, r; cin >> l >> r; l++, r++;
                cout << ft.query(l, r) << "\n";
            }
        }
    }
}

