#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        double r;
        cin >> r;

        cout << "Case " << ++cs << ": ";
        cout << fixed << setprecision(2);
        double PI = acos(-1);
        cout << r * r * (4.0 - PI) << endl;
    }
}

