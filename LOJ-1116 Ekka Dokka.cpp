#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        LL n;
        cin >> n;

        LL a = 1;

        while (n % 2 == 0) n /= 2, a *= 2;

        if (a & 1) {
            cout << "Impossible\n";
            continue;
        }

        cout << n << " " << a << "\n";
    }
}

