#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        int lx = 0, rx = 1e6;
        int ly = 0, ry = 1e6;
        int lz = 0, rz = 1e6;

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

            if (x1 > lx) lx = x1;
            if (x2 < rx) rx = x2;

            if (y1 > ly) ly = y1;
            if (y2 < ry) ry = y2;

            if (z1 > lz) lz = z1;
            if (z2 < rz) rz = z2;
        }

        LL dx = rx - lx, dy = ry - ly, dz = rz - lz;
        LL ans = max(dx * dy * dz, 0LL);

        cout << ans << "\n";
    }
}

