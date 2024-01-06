#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int main() {
    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> wish(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                int x; cin >> x;
                wish[i].push_back(x);
            }
        }

        int p;
        cin >> p;

        set<int> st;
        for (int i = 0; i < p; i++) {
            int x; cin >> x;
            st.emplace(x);
        }

        bool ok = true;

        for (auto vec : wish) {
            bool now = false;
            for (int x : vec) {
                if (x > 0 && st.count(x)) now = true;
                if (x < 0 && !st.count(-x)) now = true;
            }
            ok &= now;
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
}

