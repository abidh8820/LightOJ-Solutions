#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        map<int, string> mp;
        vector<int> v;

        for(int i=0; i<n; i++){
            string s;
            cin >> s;

            int x, y, z;
            cin >> x >> y >> z;

            int vol = x*y*z;
            v.push_back(vol);
            mp[vol] = s;
        }

        sort(v.begin(), v.end());

        if(v[0]==v.back()){
            cout <<"no thief\n";
        }
        else {
            cout<<mp[v.back()]<<" took chocolate from "<<mp[v[0]]<<"\n";
        }
    }
}

