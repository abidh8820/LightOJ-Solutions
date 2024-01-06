#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const double pi = acos(-1);
int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        double ab, ac, bc, ratio;
        cin >> ab >> ac >> bc >> ratio;

        ratio = ratio / (ratio + 1.0);

        printf("%.6lf\n", ab*sqrt(ratio));
    }
}

