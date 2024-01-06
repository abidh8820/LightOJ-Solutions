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
        string s;
        cin >> s;
    
        LL m;
        cin >> m;

        int st = (s[0]=='-'? 1 : 0);

        LL now = 0;
        for(int i=st; i<s.size(); i++){
            now = (now*10 + s[i]-'0')%m;
        }

        if(now==0) cout <<"divisible\n";
        else cout <<"not divisible\n";
    }
}

