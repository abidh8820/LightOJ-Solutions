#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int f(int n, int k) {
    if (n == 1) return 0;
    return (f(n - 1, k) + k) % n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, k;
        cin >> n >> k;

        cout << 1 + f(n, k) << "\n";
    }
}

