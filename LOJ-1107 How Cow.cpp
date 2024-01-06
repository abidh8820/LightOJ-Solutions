#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int,int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";

        int x1, y1, x2 , y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int q;
        cin >> q;

        while(q--){
            int x , y;
            cin >> x >> y;

            if(x1<=x && x<=x2 && y1<=y && y<=y2) cout <<"Yes\n";
            else cout <<"No\n";
        }
    }
}

