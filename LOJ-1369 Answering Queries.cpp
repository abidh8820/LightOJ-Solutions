#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";
        int n, q;
        cin >> n >> q;

        LL sum = 0;

        auto add = [&](LL val, int i) {
            sum += val * (n - i - 1) - (val * i);
        };

        auto del = [&](LL val, int i) {
            sum -= val * (n - i - 1) - (val * i);
        };

        vector<LL> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            add(a[i], i);
        }

        while (q--) {
            int tp;
            cin >> tp;
            if (tp == 1) {
                cout << sum << "\n";
                continue;
            }
            int id, v;
            cin >> id >> v;
            del(a[id], id);
            a[id] = v;
            add(a[id], id);
        }
    }
}

