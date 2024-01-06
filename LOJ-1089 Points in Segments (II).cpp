#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";

        int n, q;
        cin >> n >> q;

        map<int, int> ID;
        vector<int> l(n), r(n);

        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            ID[l[i]], ID[l[i] + 1], ID[l[i] - 1];
            ID[r[i]], ID[r[i] + 1], ID[r[i] - 1];
        }

        vector<int> Q(q);
        for (int i = 0; i < q; i++) {
            cin >> Q[i];
            ID[Q[i]], ID[Q[i] + 1], ID[Q[i] - 1];
        }

        int cnt = 0;
        for (auto& [x, y] : ID) y = cnt++;

        for (int i = 0; i < n; i++) {
            l[i] = ID[l[i]];
            r[i] = ID[r[i]];
        }

        for (int i = 0; i < q; i++) Q[i] = ID[Q[i]];

        vector<int> cum(cnt + 100, 0);

        for (int i = 0; i < n; i++) {
            cum[l[i]]++, cum[r[i] + 1]--;
        }

        for (int i = 1; i < cum.size(); i++) cum[i] += cum[i - 1];

        for (int i = 0; i < q; i++) {
            cout << cum[Q[i]] << "\n";
        }
    }
}

