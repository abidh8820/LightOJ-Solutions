#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 69;
char grid[N][N];
int dist[N][N];
int vis[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> grid[i][j];
            }
        }

        auto solve = [&](char c) {
            memset(dist, 0x03, sizeof dist);
            memset(vis, 0, sizeof vis);

            int sx, sy;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (grid[i][j] == c) {
                        sx = i, sy = j; break;
                    }
                }
            }

            vector<PII> Q = {{sx, sy}};
            dist[sx][sy] = 0, vis[sx][sy] = 1;

            for (int i = 0; i < Q.size(); i++) {
                auto [ux, uy] = Q[i];
                if (grid[ux][uy] == 'h') return dist[ux][uy];

                for (int k = 0; k < 4; k++) {
                    int x = ux + dx[k], y = uy + dy[k];
                    if (x > n or x < 1 or y > m or y < 1) continue;

                    if (grid[x][y] == '#' or grid[x][y] == 'm' or vis[x][y]) continue;
                    vis[x][y] = true, dist[x][y] = dist[ux][uy] + 1;
                    Q.emplace_back(x, y);
                }
            }
        };

        int ans = 0;
        for (char c : {'a', 'b', 'c'}) {
            ans = max(ans, solve(c));
        }

        cout << ans <<"\n";
    }
}

