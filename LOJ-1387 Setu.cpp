#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";
        int n;
        cin >> n;

        LL ans = 0;

        while(n--){
            string s;
            cin >> s;
            if(s=="donate"){
                int x;
                cin >> x;
                ans += x;
            }
            else cout << ans <<"\n";
        }
    }
}

