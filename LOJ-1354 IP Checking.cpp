#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

bool same(int a, int x) {
    int res = 0, cur = 0;
    while(a>0){
        if(a&1) res += (1<<cur);
        cur++, a/=10;
    }
    return res == x;
}

int main() {
    int t, cs = 0;
    scanf("%d", &t);

    while (t--) {
        printf("Case %d: ", ++cs);
        int a, b, c, d;
        scanf("%d.%d.%d.%d", &a, &b, &c, &d);

        int aa, bb, cc, dd;
        scanf("%d.%d.%d.%d", &aa, &bb, &cc, &dd);
        
        bool ok = true;
        ok &= same(aa, a);
        ok &= same(bb, b);
        ok &= same(cc, c);
        ok &= same(dd, d);

        printf(ok ? "Yes\n" : "No\n");
    }
}

