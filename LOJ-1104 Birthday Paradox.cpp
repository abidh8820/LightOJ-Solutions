#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PLL;

const double PI = acos(-1), EPS = 1e-9;
int dcmp(long double x) { return abs(x) < EPS ? 0 : (x < 0 ? -1 : 1); }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        long double prob = 1.0;

        for (int i = 1; i <= n+1; i++) {
            prob *= (n - i + 1.0) / (1.0 * n);
            if (prob <= 0.5) {
                cout << i - 1 << endl;
                break;
            }
        }
    }
}

