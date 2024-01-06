#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 27;
const int INF = 1e6;

bool vis[N][N][N];
bool bad[N][N][N];
int dist[N][N][N];

tuple<int, int, int> del[] = {
    {1, 0, 0},
    {-1, 0, 0},
    {0, 1, 0},
    {0, -1, 0}, 
    {0, 0, 1},
    {0, 0, -1}
};

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        string start, end;
        cin >> start >> end;

        memset(vis, false, sizeof vis);
        memset(bad, false, sizeof bad);
        memset(dist, 0x0b, sizeof dist);

        int q;
        cin >> q;

        for(int i=0; i<q; i++) {
            string a, b, c;
            cin >> a >> b >> c;

            for (char x : a)
                for (char y : b)
                    for (char z : c) bad[x - 'a'][y - 'a'][z - 'a'] = true;
        }

        vector<tuple<int, int, int>> Q = {{
            start[0] - 'a',
            start[1] - 'a',
            start[2] - 'a'
        }};

        auto [x, y, z] = Q[0];

        if (bad[x][y][z]) {
            cout << -1 << "\n";
            continue;
        }

        vis[x][y][z] = true;
        dist[x][y][z] = 0;

        for (int i = 0; i < Q.size(); i++) {
            auto [ux, uy, uz] = Q[i];

            for (auto [dx, dy, dz] : del) {
                int vx = (ux + dx + 26) % 26;
                int vy = (uy + dy + 26) % 26;
                int vz = (uz + dz + 26) % 26;
                if (!bad[vx][vy][vz] && !vis[vx][vy][vz]) {
                    Q.push_back({vx, vy, vz});
                    vis[vx][vy][vz] = true;
                    dist[vx][vy][vz] = dist[ux][uy][uz] + 1;
                }
            }
        }

        int ans = dist[end[0] - 'a'][end[1] - 'a'][end[2] - 'a'];
        if (ans > INF) cout << "-1\n";
        else cout << ans << endl;
    }
}

