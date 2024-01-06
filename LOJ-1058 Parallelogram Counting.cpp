#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;
typedef pair<int, int> PII;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    size_t operator()(uint64_t x) const { return splitmix64(x + FIXED_RANDOM); }

    size_t operator()(pair<int, int> x) const {
        return splitmix64((uint64_t(x.first) << 32) + x.second + FIXED_RANDOM);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n;
        cin >> n;

        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        LL ans = 0;
        gp_hash_table<PII, int,custom_hash> cnt;;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                LL x1 = x[i], y1 = y[i];
                LL x2 = x[j], y2 = y[j];

                LL dx = x2 + x1, dy = y2 + y1;


                ans += cnt[PII(dx, dy)];
                cnt[PII(dx, dy)]++;
            }
        }

        cout << ans << endl;
    }
}

