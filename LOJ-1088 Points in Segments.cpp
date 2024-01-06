#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ":\n";
        int n, q;
        cin >> n >> q;

        vector<int> points(n);
        for (int i = 0; i < n; i++) cin >> points[i];

        auto count = [&](int x){
            int it = upper_bound(points.begin(), points.end(), x) - points.begin();
            return it;
        };
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;

            cout << count(r) - count(l - 1) << endl;
        }
    }
}

