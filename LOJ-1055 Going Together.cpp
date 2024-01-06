#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 11;
int dist[N][N][N][N][N][N];
int n;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

char grid[N][N];

bool is_val(int x, int y) {
    if (x <= 0 || x > n || y <= 0 || y > n) return false;
    return (grid[x][y] != '#');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        cin >> n;

        map<char, PII> pos;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> grid[i][j];
                pos[grid[i][j]] = PII(i, j);
            }
        }

        auto [x1, y1] = pos['A'];
        auto [x2, y2] = pos['B'];
        auto [x3, y3] = pos['C'];

        memset(dist, 0x0b, sizeof dist);

        dist[x1][y1][x2][y2][x3][y3] = 0;
        int ans = 1e9 + 7;

        vector<tuple<int, int, int, int, int, int, int>> Q = { {0, x1, y1, x2, y2, x3, y3}};
        for (int i = 0; i < Q.size(); i++) {
            auto [d, x1, y1, x2, y2, x3, y3] = Q[i];

            if(grid[x1][y1]=='X' && grid[x2][y2]=='X' && grid[x3][y3]=='X'){
                ans = d; break;
            }

            for (int k = 0; k < 4; k++) {
                int xx1 = x1 + dx[k], yy1 = y1 + dy[k];
                int xx2 = x2 + dx[k], yy2 = y2 + dy[k];
                int xx3 = x3 + dx[k], yy3 = y3 + dy[k];

                if(!is_val(xx1, yy1)) xx1 = x1, yy1 = y1;
                if(!is_val(xx2, yy2)) xx2 = x2, yy2 = y2;
                if(!is_val(xx3, yy3)) xx3 = x3, yy3 = y3;

                if(xx1==xx2 && yy1==yy2) xx1 = x1, yy1 = y1, xx2 = x2, yy2 = y2;
                if(xx1==xx3 && yy1==yy3) xx1 = x1, yy1 = y1, xx3 = x3, yy3 = y3;
                if(xx2==xx3 && yy2==yy3) xx2 = x2, yy2 = y2, xx3 = x3, yy3 = y3;

                if(xx1==xx2 && yy1==yy2) continue;
                if(xx1==xx3 && yy1==yy3) continue;
                if(xx2==xx3 && yy2==yy3) continue;


                int& d2 = dist[xx1][yy1][xx2][yy2][xx3][yy3];

                if (d2 > 1 + d) {
                    d2 = d + 1;
                    Q.emplace_back(d2, xx1, yy1, xx2, yy2, xx3, yy3);
                }
            }
        }


        if (ans >= 10000000) cout << "trapped\n";
        else cout << ans << "\n";
    }
}

