#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1005;
int dp[N][N];

int dx[] = {-2, -3, -2, -1, -1, 1};
int dy[] = {1, -1, -1, -2, -3, -2};

int grundy(int x, int y) {
    if (~dp[x][y]) return dp[x][y];

    set<int> st;
    for (int i = 0; i < 6; i++)  {
        if(x+dx[i]<0 or y+dy[i]<0) continue;
        st.insert(grundy(x + dx[i], y + dy[i]));
    }

    for (int i = 0; i < N; i++) 
        if (!st.count(i)) { dp[x][y] = i; break; }

    return dp[x][y];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof dp);
    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n; cin >> n;
        int XOR = 0;

        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            XOR ^= grundy(x, y);
        }
        cout << (XOR ? "Alice" : "Bob") << "\n";
    }
}

