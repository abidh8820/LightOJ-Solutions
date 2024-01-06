#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        LL n;
        cin >> n;

        int idx = -1;
        for (int i = 0; i <= 34; i++) {
            if ((n >> i & 1) && !(n >> (i + 1) & 1)) {
                idx = i, n += (1 << i);
                break;
            }
        }

        int cnt = 0;
        for (int i = idx; i >= 0; i--) 
            if (n >> i & 1) cnt++, n -= (1 << i);

        for (int i = 0; i < cnt; i++) n += (1 << i);
        cout << n << endl;
    }
}

