#include <bits/stdc++.h>
using namespace std;
 
using LL = long long;
using PII = pair<LL, LL>;


const LL N = 51;
LL dp[N][N][N][N];

LL call(int bar, int seg, int cur, int mx){
    if(bar < 0 or seg < 0 or cur > mx) return 0;
    if(bar == 0 and seg == 0) return 1;

    LL&ret = dp[bar][seg][cur][mx];
    if(~ret) return ret;

    ret = 0;
    ret += call(bar - 1, seg, cur + 1, mx);
    ret += call(bar - 1, seg - 1, 1, mx);
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL t, cs = 0;
    cin >> t;

    memset(dp, -1, sizeof dp);
    while(t--){
        cout <<"Case "<<++cs<<": ";
        int n, k, m;
        cin >> n >> k >> m;
        cout << call(n - 1 , k - 1, 1, m) << "\n";
    }

}
