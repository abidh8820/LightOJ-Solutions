#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int M = 10000019;
const int N = 1e6 + 7;

int bpf[N];
vector<int> primes;

void sieve() {
    for (int i = 2; i < N; i++) {
        if (bpf[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < N; j += i) bpf[j] = i;
        }
    }
}

int power(int x, int y) {
    int ans = 1;
    for (; y; y >>= 1, x = 1LL * x * x % M)
      if (y & 1) ans = 1LL * ans * x % M;
    return ans;
}
int find_power(int n, int p){
    int ans = 0;
    while(n > 0) n /= p, ans += n;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, k;
        cin >> n >> k;

       
        int ans = 1;
        for(int p : primes){
            int pw = find_power(n, p);
            if(pw < k ) break;
            ans = 1LL* ans * power(p, pw / k) % M;
        }
        if(ans == 1) ans = -1;
        cout << ans << "\n";
    }
}

