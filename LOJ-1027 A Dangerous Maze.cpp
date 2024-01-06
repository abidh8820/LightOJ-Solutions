#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;
    
    while(t--){
        cout<<"Case "<<++cs<<": ";
        
        int n;
        cin >> n;
    
        int k = 0;
        long long up = 0;

        for (int i = 0; i < n; i++) {
            int x;cin >> x;
            if (x < 0) k++;
            up += abs(x);
        }

        long long down = n - k;
        long long g = __gcd(down, up);

        if (down == 0) {
            cout << "inf" << endl;
            continue;
        }

        up /= g, down /= g;
        cout << up << "/" << down << endl;
    }
}

