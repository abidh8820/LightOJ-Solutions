#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PLL;

LL lcm(LL a, LL b) { return a / __gcd(a, b) * b; }
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, m;
        cin >> n >> m;

        vector<LL> nums(m);
        for (auto& i : nums) cin >> i;
        LL ans = 0;

        for (int mask = 1; mask < (1 << m); mask++) {
            int cnt = __builtin_popcount(mask);
            LL val = 1;
            for (int i = 0; i < m && val <= n; i++) {
                if (mask >> i & 1) val = lcm(val, nums[i]);
            }
            if (val > n) continue;
            ans += (n / val) * (cnt & 1 ? 1 : -1);
        }

        cout << n-ans << endl;
    }
}

