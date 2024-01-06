#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using LL = long long;
using PLL = pair<LL, LL>;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        gp_hash_table<int, bool, custom_hash> table;
        table[0] = true; bool ok = false;

        function<void(int, int, int)> backtrack = [&](int idx, int sum, int lim) {
            if (ok) return;

            if (idx >= lim) {
                int need = k - sum;
                if (idx > n / 2) ok |= table[need];
                else table[sum] = true;
                return;
            }
            backtrack(idx + 1, sum, lim);
            backtrack(idx + 1, sum + a[idx], lim);
            backtrack(idx + 1, sum + 2 * a[idx], lim);
        };

        backtrack(0, 0, n / 2);
        backtrack(n / 2, 0, n);

        cout << (ok ? "Yes" : "No") << "\n";
    }
}

