#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const double pi = acos(-1);
int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        double R, n;
        cin >> R >> n;

        double ang = (pi) / n;
        double ans = R * sin(ang) / (1 + sin(ang));
        cout << fixed << setprecision(10) << ans << endl;
    }
}

