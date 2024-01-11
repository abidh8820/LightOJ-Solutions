#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int grundy(int n) {
    if (n < 2) return 0;
    if (n % 2 == 0) return (n / 2);
    return grundy(n / 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n;
        cin >> n;

        LL XOR = 0;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            XOR ^= grundy(x);
        }

        cout << (XOR ? "Alice" : "Bob") << "\n";
    }
}

