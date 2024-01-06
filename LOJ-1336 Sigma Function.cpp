#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<LL> perfect;
    for (int i = 3; i < N; i += 2) perfect.push_back(1LL*i * i);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        LL n;
        cin >> n;

        LL now = 1, ans = 0;
        while (now < 1LL * N * N) {
            for (LL x : perfect) {
                if (x * now <= n) ans++;
                else break;
            }
            now *= 2;
        }

        ans = n - ans;
        for (LL now = 1; now <= n; now *= 2) ans--;
        cout << ans << "\n";
    }
}

