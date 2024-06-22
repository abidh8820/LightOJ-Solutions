#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 7, M = 1000007;
int a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int k, c, n;
        cin >>  k >> c >> n >> a[0];

        for(int i = 1; i < n; i++){
            a[i] = (1LL * k * a[i - 1] + c) % M;
        }
        sort(a, a + n);

        LL ans = 0;
        for(int i = 0; i < n; i++){
            ans += 1LL * i * a[i] - 1LL * (n - i - 1) * a[i];
        }

        cout << ans << '\n';
    }
}

