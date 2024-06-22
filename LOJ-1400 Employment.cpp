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

        int n; cin >> n;
        vector<vector<int>> pref_men(n, vector<int>(n)), rank_men(n, vector<int>(n));
        vector<int> itr(n, 0);

        //stable marriage problem using Gale–Shapley algorithm

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> pref_men[i][j];
                pref_men[i][j] -= n + 1;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int man; cin >> man;
                rank_men[i][man - 1] = j;
            }
        }

        vector<int> freemen(n), eng(n, -1);
        iota(freemen.begin(), freemen.end(), 0);

        for(int i = 0; i < freemen.size(); i++){
            int man = freemen[i];
            for(; itr[man] < n; itr[man]++){
                int j = itr[man], woman = pref_men[man][j];

                if(eng[woman] == -1){ eng[woman] = man; break; }

                else {
                    int other = eng[woman];
                    if(rank_men[woman][man] < rank_men[woman][other]){
                        freemen.push_back(other), eng[woman] = man; break;
                    }
                }
            }
        }

        vector<PII> ans;
        for(int i = 0; i < n; i++) ans.emplace_back(eng[i] + 1, i + n + 1);
        sort(ans.begin(), ans.end());

        for(auto[x, y] : ans) cout << "(" <<  x << " " << y <<  ")" << " ";
        cout <<"\n";
    }
}

