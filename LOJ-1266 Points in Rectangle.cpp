#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1008;
int bit[N][N], n, m;
int a[N][N], q;

void update(int x, int y, int val) {
    for (; x < N; x += -x & x)
        for (int j = y; j < N; j += -j & j) bit[x][j] += val;
}

int get(int x, int y) {
    int ans = 0;
    for (; x; x -= x & -x)
        for (int j = y; j; j -= j & -j) ans += bit[x][j];
    return ans;
}

int get(int x1, int y1, int x2, int y2) {
    return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";
        int q;
        cin >> q;
        
        memset(bit, 0, sizeof bit);

        while (q--) {
            int type;
            cin >> type;
            if (type == 0) {
                int x, y;
                cin >> x >> y;
                x++, y++;
                if (get(x, y, x, y)) continue;
                update(x, y, 1);
            } else {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                x1++, y1++, x2++, y2++;
                cout << get(x1, y1, x2, y2) << "\n";
            }
        }
    }
}

