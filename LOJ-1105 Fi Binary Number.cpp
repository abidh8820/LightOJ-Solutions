#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;


const int N = 45;
LL fib[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < N; i++) fib[i] = fib[i - 1] + fib[i - 2];

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        bool ok = false;
        LL n;
        cin >> n;
        for(int i = N - 1; i >= 1; i--){
            if(fib[i] <= n){
                cout << 1;
                ok = true, n -= fib[i];
            } 
            else if(ok) cout << 0;
        }
        cout << "\n";
    }
}

