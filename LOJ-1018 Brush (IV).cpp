#include <bits/stdc++.h>

using namespace std;

int n;
const int N = 1 << 17;

int dp[17][N];

template <typename T>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
};

vector<Point<int>> pnt;
vector<int> adj[17][17];

bool colinear(Point<int> a, Point<int> b, Point<int> c) {
    return ((a.y - b.y) * (b.x - c.x)) == (a.x - b.x) * (b.y - c.y);
}
int call(int pos, int mask) {
    if (pos == n) return 0;
    int &ret = dp[pos][mask];
    if (ret != -1) return ret;

    if (mask >> pos & 1) return dp[pos][mask] = call(pos + 1, mask);
    ret = call(pos + 1, mask | (1 << pos)) + 1;

    for (int i = pos + 1; i < n; i++) {
        if (mask >> i & 1) continue;
        int tmask = mask;
        tmask |= 1 << pos, tmask |= 1 << i;
        for(int j=i+1; j<n; j++) {
            if(colinear(pnt[pos],pnt[i],pnt[j])) tmask |= (1<<j);
        }
        ret = min(ret, call(pos + 1, tmask) + 1);
    }
    return ret;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, c = 0;
    cin >> t;

    while (t--) {
        cin >> n;

        pnt.clear();
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            Point<int> p(x, y);
            pnt.push_back(p);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                adj[i][j].clear();
            }
        }

        for(int i=0; i<=n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; j<n; j++) {
                    if(colinear(pnt[i],pnt[j],pnt[k])) adj[i][j].push_back(k);
                }
            }
        }

        memset(dp, -1, sizeof dp);

        cout << "Case " << ++c << ": ";
        cout << call(0, 0) << endl;
    }
}
