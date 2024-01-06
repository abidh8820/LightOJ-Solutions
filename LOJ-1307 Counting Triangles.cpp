#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        int ans = 0;

        for (int j = n - 1; j >= 0; j--) {
            for (int i = j - 1; i >= 0; i--) {
                int lo = j+1, hi = n-1, k = -1;
                while(lo <= hi){
                    int mid = lo + hi >> 1;
                    if(a[i]+a[j] > a[mid]) k = mid , lo = mid + 1;
                    else hi = mid - 1;
                }
                if(k!=-1) ans += k-j;
            }
        }

        cout << ans << "\n";
    }
}

