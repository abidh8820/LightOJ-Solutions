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
        double n, m, k, p;
        cin >> n >> m >> k >> p;


        cout <<fixed<<setprecision(10)<<n*k*p<<"\n";
    }
}

