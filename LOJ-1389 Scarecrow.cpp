#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        string s;
        cin >> s;

        int cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (cnt == 2) { ans++, cnt = 0; continue; }
            if (cnt) { cnt++; continue; }
            if(s[i]=='.') cnt++;
        }
        if(cnt) ans++;

        cout << ans << "\n";
    }
}

