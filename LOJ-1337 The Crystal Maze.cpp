#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 505;

char grid[N][N];
int cnt[N][N];
int vis[N][N];
int ans[N][N];
int n, m, q;
int t, cs = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int now = 0;

vector<PII> current;

void dfs(int x, int y) {
    if (x > n or x < 1 or y > m or y < 1) return;
    if (vis[x][y] == cs) return;
    if (grid[x][y] == '#') return;

    vis[x][y] = cs;
    if (grid[x][y] == 'C') now++;
    current.emplace_back(x, y);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";

        cin >> n >> m >> q;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> grid[i][j];
            }
        }

        memset(ans, 0, sizeof ans);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i][j] == '.' && vis[i][j] != cs) {
                    current.clear();
                    now = 0, dfs(i, j);
                    for (auto [x, y] : current) ans[x][y] = now;
                }
            }
        }

        while (q--) {
            int x, y;
            cin >> x >> y;
            cout << ans[x][y] << "\n";
        }
    }
}

