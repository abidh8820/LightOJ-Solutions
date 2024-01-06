#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
typedef long long LL;

int main() {
    int t, cs = 0;
    cin >> t;

    while (t--) {
        LL n;
        cin >> n;

        cout << "Case " << ++cs << ": " << n << " = ";
        map<int, int> mp;

        for (int i = 2; i <= n; i++) {
            int cur = i;

            for (int j = 2; j * j <= cur; j++) {
                while (cur % j == 0) mp[j]++, cur /= j;
            }
            if (cur > 1) mp[cur]++;
        }

        int cnt = 0;
        for (auto [x, y] : mp) {
            if (cnt) printf(" * ");
            cnt = 1;
            printf("%d (%d)", x, y);
        }
        cout << endl;
    }
}

