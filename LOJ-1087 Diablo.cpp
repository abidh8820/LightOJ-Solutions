#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

        map<int, int> val;
        ordered_set alive;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            val[++cnt] = x;
            alive.insert(cnt);
        }

        while (q--) {
            char ch;
            cin >> ch;

            if (ch == 'c') {
                int k; cin >> k;
                int lo = 0, hi = cnt, ans = -1;

                while (lo <= hi) {
                    int mid = lo + hi >> 1;
                    int upto = alive.order_of_key(mid);
                    if (upto >= k - 1) {
                        ans = mid, hi = mid - 1;
                    } else lo = mid + 1;
                }

                if (ans == -1) {
                    cout << "none\n";
                    continue;
                }

                auto it = alive.upper_bound(ans - 1);
                if (it == alive.end()) {
                    cout << "none\n";
                    continue;
                }

                cout << val[*it] << "\n";
                alive.erase(*it);
            }
            else {
                int x; cin >> x;
                val[++cnt] = x;
                alive.insert(cnt);
            }
        }
    }
}

