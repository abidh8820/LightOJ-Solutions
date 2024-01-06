#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int,int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n;
        cin >> n;

        int XOR = 0;

        for(int i=0; i<n; i++){
            int a, b;
            cin >> a >> b;

            XOR ^= (b-a-1);
        }

        if(XOR) cout <<"Alice\n";
        else cout <<"Bob\n";
    }
}

