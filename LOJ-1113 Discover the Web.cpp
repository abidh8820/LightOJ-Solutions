#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";
        string com;

        stack<string> fs, bs;
        string cur = "http://www.lightoj.com/";
        while (cin >> com) {
            if(com=="QUIT") break;
            if(com=="BACK"){
                if(bs.empty()){
                    cout<<"Ignored\n";
                }
                else {
                    fs.push(cur);
                    cur = bs.top();
                    bs.pop();
                    cout <<cur<<"\n";
                }
            }
            if(com=="FORWARD"){
                if(fs.empty()){
                    cout<<"Ignored\n";
                }
                else {
                    bs.push(cur);
                    cur = fs.top();
                    fs.pop();
                    cout << cur <<"\n";
                }
            }
            if(com=="VISIT"){
                bs.push(cur);
                cin >> cur;
                cout << cur <<"\n"; 
                while(fs.size()) fs.pop();
            }
        }
    }
}

