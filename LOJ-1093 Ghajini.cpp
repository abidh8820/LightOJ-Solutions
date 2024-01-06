#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n, d;
        cin >> n >> d;

        vector<int> a(n);
        multiset<int> st;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            st.insert(a[i]);
            if (i - d >= 0) {
                st.erase(st.find(a[i - d]));
            }
            if (st.size() == 1) continue;
            int mx = *st.rbegin();
            int mn = *st.begin();
            ans = max(ans, mx - mn);
        }

        cout << ans << endl;
    }
}

