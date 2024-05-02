#include <bits/stdc++.h>
using namespace  std;

using LL = long long;

const int B = 20, N = 22;
vector<int> bounds;

LL dp[N][N][2][2][2];

LL call(int l, int r, bool lead, bool prefsmall, bool suffbig) {
    if(l > r){
        if(r == B -1) return 0;
        if(prefsmall) return 1;
        if(!suffbig) return 1;
        return 0;
    }
    
    LL& ret = dp[l][r][lead][prefsmall][suffbig];
    if(~ret) return ret; ret = 0;
    
    int lim = prefsmall? 9 : bounds[l];
    for(int i = 0; i <= lim; i++) {
        int next_r = (i>0 or lead? r - 1 : r);
        int next_prefsmall = prefsmall | (i < lim);
        int next_suffbig = suffbig;
        if(next_r < r && i > bounds[r]) next_suffbig = true;
        if(next_r < r && i < bounds[r]) next_suffbig = false;
        ret += call(l + 1, next_r, lead | (i > 0), next_prefsmall, next_suffbig);
    }
    return ret;
}


LL solve(LL n){
    bounds.clear();
    for(int i = 0; i < B; i++) bounds.push_back(n % 10), n /= 10;
    reverse(bounds.begin(), bounds.end());
    memset(dp, -1, sizeof dp);
    return call(0, B - 1, 0, 0, 0) + 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int t, cs = 0;
    cin >> t;
    while(t--){
        cout <<"Case "<<++cs <<": ";
        LL l, r; cin >> l >> r;
        if(l > r) swap(l, r);
        cout << solve(r) - (l ? solve(l - 1) : 0) << "\n";
    }
}

