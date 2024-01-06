#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

const int N = 20;
const int INF = 1e6 + 7;
int t, cs = 0, sx, sy;

int dist[N][N][N][N];
vector<PII> golds;

int dp[16][1 << 16];
int fg[16][1 << 16];

int call(int idx, int mask) {
    auto [x, y] = golds[idx];
    if (__builtin_popcount(mask) == golds.size()) {
        return dist[x][y][sx][sy];
    }

    if (fg[idx][mask] == cs) return dp[idx][mask];
    int& ret = dp[idx][mask];

    ret = INF;
    fg[idx][mask] = cs;

    for (int i = 1; i < golds.size(); i++) {
        if (!(mask >> i & 1)) {
            auto [nx, ny] = golds[i];
            ret = min(ret, call(i, mask | (1 << i)) + dist[x][y][nx][ny]);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    memset(fg, -1, sizeof fg);

    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n, m;
        cin >> n >> m;

        char grid[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < m; l++) {
                        dist[i][j][k][l] = INF;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<PII> Q = {{i, j}};
                dist[i][j][i][j] = 0;

                for (int idx = 0; idx < Q.size(); idx++) {
                    auto [ux, uy] = Q[idx];

                    for (int k = 0; k < 8; k++) {
                        int x = ux + dx[k];
                        int y = uy + dy[k];

                        if (x < 0 || x >= n || y < 0 || y >= m) continue;

                        if (dist[i][j][x][y] > dist[i][j][ux][uy] + 1) {
                            dist[i][j][x][y] = dist[i][j][ux][uy] + 1;
                            Q.push_back({x, y});
                        }
                    }
                }
            }
        }

        sx = -1, sy = -1;
        golds.clear();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'g') golds.emplace_back(i, j);
                if (grid[i][j] == 'x') sx = i, sy = j;
            }
        }

        golds.push_back({sx,sy});
        reverse(golds.begin(), golds.end());
        assert(sx != -1);

        if (golds.size() == 1) {
            cout << 0 << "\n";
            continue;
        }

        cout << call(0, 1) << "\n";
    }
}

