#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<LL, LL>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";
        LL n, m;
        cin >> n >> m;

        vector<LL> a(n);
        for (LL i = 0; i < n; i++) cin >> a[i];

        while (m--) {
            char ch;
            cin >> ch;

            if (ch == 'S') {
                LL d;
                cin >> d;
                for (LL i = 0; i < n; i++) a[i] += d;
            } else if (ch == 'M') {
                LL d;
                cin >> d;
                for (LL i = 0; i < n; i++) a[i] *= d;
            } else if (ch == 'D') {
                LL k;
                cin >> k;
                for (LL i = 0; i < n; i++) a[i] /= k;
            } else if (ch == 'P') {
                LL x, y;
                cin >> x >> y;
                swap(a[x], a[y]);
            } else {
                reverse(a.begin(), a.end());
            }
        }
        for(LL x : a ) cout <<x<<" ";
        cout <<endl;
    }
}

