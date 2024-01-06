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
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        map<int,int> mp;
        LL ans = 0;
        for(int i=1; i<=n; i++){
            int x; cin >> x;
            if(x) mp[x]++;
            else ans++;
        }

        for(auto[x, cnt] : mp){
           ans += (x+1) * ((cnt+x)/(x+1));
        }
        cout << ans <<"\n";
    }
}

