#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PLL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";
        int n;
        cin >> n;

        map<string, int> cnt;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if(s.size()>1)sort(s.begin() + 1, s.end() - 1);
            cnt[s]++;
        }

        int m;
        cin >> m;

        cin.ignore();
        for (int i = 0; i < m; i++) {
            string s;
            getline(cin, s);
            
            LL ans = 1;
            stringstream ss(s);
            string now;
            while (ss >> now) {
                if(now.size()>1)sort(now.begin() + 1, now.end() - 1);
                ans *= cnt[now];
            }
            cout << ans << endl;
        }
    }
}

