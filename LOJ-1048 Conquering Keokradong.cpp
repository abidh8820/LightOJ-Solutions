#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, k;
        cin >> n >> k;

        vector<int> v(n + 1);
        for (int i = 0; i <= n; i++) cin >> v[i];

        auto check = [&](int mid) {
            int cnt = 0, cur = 0;
            vector<int> arr;

            for (int x : v) {
                if (x > mid) return make_pair(vector<int>{0}, 1000000000);
                if (cur + x <= mid)
                    cur += x;
                else {
                    arr.push_back(cur);
                    cnt++, cur = x;
                }
            }

            arr.push_back(cur);
            return make_pair(arr, cnt);
        };

        int lo = 1, hi = 1e9, ans = -1;
        while (lo <= hi) {
            int mid = lo + hi >> 1;
            auto [arr, nights] = check(mid);
            if (nights <= k) {
                ans = mid, hi = mid - 1;
            } else
                lo = mid + 1;
        }

        auto [arr, mx] = check(ans);
        cout << ans << "\n";

        int kom = n - k;
        for (int i = 0; i <= n - 1 && kom > 0; i++) {
            if (v[i] + v[i + 1] <= ans) {
                v[i + 1] += v[i];
                v[i] = 0, kom--;
            }
        }

        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            if (v[i]) cout << v[i] << "\n", cnt++;
        }
        assert(cnt==k+1);

    }
}

