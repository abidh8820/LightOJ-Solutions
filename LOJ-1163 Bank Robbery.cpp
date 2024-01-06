#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        long long n;
        cin >> n;
        cout << "Case " << i << ": ";
        if (n == 9) cout << 10 << endl;
        else if (n % 9 == 0) { cout << (n + n / 9) - 1 << " " << n + n / 9 << endl;

        } else cout << n + n / 9 << endl;
    }
}
