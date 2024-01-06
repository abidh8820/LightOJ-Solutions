#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        vector<int> a(3);
        for (int i = 0; i < 3; i++) cin >> a[i];

        sort(a.begin(), a.end());

        if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) printf("yes\n");
        else printf("no\n");
    }
}

