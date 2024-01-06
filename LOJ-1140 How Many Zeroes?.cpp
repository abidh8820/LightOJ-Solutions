#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<LL, LL>;

LL dp[11][2][2][2][11];

vector<LL> L, R;

LL call(LL pos, bool loose_low, bool loose_hi,bool lead,  LL cnt) {
    if (pos == R.size()) return cnt;
    LL &ret = dp[pos][loose_low][loose_hi][lead][cnt];

    if (~ret) return ret;
    ret = 0;

    LL lo = L[pos], hi = R[pos];
    if (loose_low) lo = 0;
    if (loose_hi) hi = 9;

    for (LL i = lo; i <= hi; i++) {
        bool n_loose_hi = loose_hi | (R[pos] > i);
        bool n_loose_low = loose_low | (i > L[pos]);

        bool n_lead = lead|(i>0);
        int n_cnt = lead? cnt+(i==0) : cnt;
        ret += call(pos + 1, n_loose_low, n_loose_hi, n_lead, n_cnt);
    }

    return ret;
}

int main() {
    LL t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        memset(dp, -1, sizeof dp);

        string A, B;
        cin >> A >> B;

        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        LL mx = max(A.size(), B.size());

        while (A.size() < mx) A += '0';
        while (B.size() < mx) B += '0';

        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());

        R.resize(mx), L.resize(mx);

        for (LL i = 0; i < mx; i++) {
            R[i] = B[i] - '0';
            L[i] = A[i] - '0';
        }


        LL ans = call(0,0,0,0,0);
        bool ok = true;

        for(int x : L) if(x) ok = false;
        if(ok) ans++;
        cout << ans <<"\n";
    }
}

