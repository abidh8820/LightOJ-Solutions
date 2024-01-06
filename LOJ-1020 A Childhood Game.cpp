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

        string s;
        cin >> s;

        if (s == "Alice") {
            if (n % 3 == 1)  cout << "Bob" << endl;
            else cout << "Alice" << endl;
        } 
        else {
            if (n % 3 == 0)  cout << "Alice" << endl;
            else  cout << "Bob" << endl;
        }
    }
}

