#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) {/* Not much */}
#endif

using LL = long long;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while(t--){
        cout << "Case " << ++cs <<": ";
        double a, b;
        char colon;
        cin >> a >> colon >> b;

        double len = sqrt(a * a * .5 * .5 + .5 * .5 * b * b);
        double theta = acos(1.0 - b * b / (2.0 * len * len));
        dbg(a, b, theta, len);

        double x = 200.0 / (a + theta * len);
        cout << fixed << setprecision(10) << a * x << " " << b * x << "\n";
        
    }
}

