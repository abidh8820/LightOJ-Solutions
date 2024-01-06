#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

LL find(LL x) {
    if (x % 3 == 0) return x - x / 3;
    else return x - (x / 3) - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        LL a, b;
        cin >> a >> b;

        cout << find(b) - find(a - 1) << "\n";
    }
}

