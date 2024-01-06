#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        LL x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if((x1+y1)%2 != (x2+y2)%2) cout <<"impossible\n";
        else if(x1-y1==x2-y2 or x1+y1==x2+y2) cout << "1\n";
        else cout<<"2\n";
    }
}

