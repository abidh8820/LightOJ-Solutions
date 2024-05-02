#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 1e6 + 7;

using DT = LL;
using LT = LL;

constexpr DT I = -1e9; 
constexpr LT None = 0;

DT val[4 * N];
LT lz[4 * N];
int L, R;

void apply(int u, const LT &U, int l, int r) {
    if(U == None) return;
    val[u] += (r - l + 1) * U;
   
    if(lz[u] == None) lz[u] = U;
    else lz[u] += U;
}

DT merge(const DT &a, const DT &b, int l, int r) {
    return max(a, b);
}

/* -- Do Not Touch Anything Below This -- */

void push(int l, int r, int u) {
    if(l == r) return;
    apply(u << 1, lz[u], l, (l + r) >> 1);
    apply(u << 1 | 1, lz[u], (l + r + 2) >> 1, r);
    lz[u] = None;
}

void build(int l, int r, vector <DT> &v, int u = 1 ) {
    lz[u] = None;
    if(l == r) {
        val[u] = v[l];
        return;
    }
    int m = (l + r) >> 1, lft = u << 1, ryt = lft | 1;
    build(l, m, v, lft);
    build(m + 1, r, v, ryt);
    val[u] = merge(val[lft], val[ryt], l, r);
}
void update(int ql,int qr, LT uval, int l = L, int r = R, int u = 1) {
    if(ql > qr) return;
    if(ql == l and qr == r) {
        apply(u, uval, l, r);
        return;
    }
    push(l, r, u);
    int m = (l + r) >> 1, lft = u << 1, ryt = lft | 1;
    update(ql, min(m, qr), uval,  l,  m, lft);
    update(max(ql, m + 1), qr, uval, m + 1, r, ryt);
    val[u] = merge(val[lft], val[ryt], l, r);
}
DT query(int ql, int qr, int l = L, int r = R, int u = 1) {
    if(ql > qr) return I;
    if(l == ql and r == qr) return val[u];
    push(l, r, u);
    int m = (l + r) >> 1, lft = u << 1, ryt = lft | 1;
    DT ansl = query(ql, min(m, qr), l, m, lft);
    DT ansr = query(max(ql, m + 1), qr, m + 1, r, ryt);
    return merge(ansl, ansr, l, r);
}

void init(int _L, int _R, vector <DT> &v) {
    L = _L, R = _R;
    build(L, R, v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";

        int n, c, q;
        cin >> n >> c >> q;

        vector<LL> a(n), pref(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        for(int i = 0; i < n; i++){
            pref[i] = 1;
            if(i > 0 && a[i] == a[i - 1]) pref[i] += pref[i - 1];
        }
        
        init(0, n - 1, pref);
        while(q--){
            int l, r; cin >> l >> r; l--, r--;
            int lo = 1, hi = r - l + 1, ans = 0;
            while(lo <= hi){
                int mid = lo + hi >> 1, l_ = l + mid - 1;
                if(query(l_, r) >= mid) ans = mid, lo = mid + 1;
                else hi = mid - 1;
            }
            cout << ans << "\n";
        }
    }
}

