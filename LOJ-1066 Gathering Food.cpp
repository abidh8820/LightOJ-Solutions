#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 1e6 + 7;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n;
        cin >> n;

        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        char mx = 'A';
        map<char, PII> pos;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] >= 'A' && s[i][j] <= 'Z') {
                    mx = max(mx, s[i][j]);
                    pos[s[i][j]] = make_pair(i, j);
                }
            }
        }

        if (mx == 'A') {
            cout << 0 << "\n";
            continue;
        }


        int ans = 0;
        set<char> valid = {'A', '.'};

        for (char source = 'A'; source < mx; source++) {
            valid.insert(char(source+1));
            auto [sx, sy] = pos[source];

            vector<vector<int>> cost(200, vector<int>(200,INF));
            vector<vector<bool>> vis(200, vector<bool>(200,false));

            cost[sx][sy] = 0, vis[sx][sy] = true;
            vector<PII> Q = {{sx, sy}};

            for (int i = 0; i < Q.size(); i++) {
                auto [ux, uy] = Q[i];
                for (int k = 0; k < 4; k++) {
                    int vx = ux + dx[k];
                    int vy = uy + dy[k];

                    if (vx < 0 || vy < 0 || vx >= n || vy >= n) continue;
                    if (vis[vx][vy] || !valid.count(s[vx][vy])) continue;

                    vis[vx][vy] = true;
                    cost[vx][vy] = cost[ux][uy] + 1;
                    Q.emplace_back(vx, vy);
                }
            }

            auto [dex, dey] = pos[source + 1];
            ans += cost[dex][dey];
        }

        if (ans >= INF) cout << "Impossible\n";
        else cout << ans << "\n";
    }
}

