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
        cout << "Case " << ++cs << ":\n";

        int n, q;
        cin >> n >> q;

        deque<int> dq;

        for (int i = 0; i < q; i++) {
            string op;
            cin >> op;

            if (op == "pushLeft") {
                int x;
                cin >> x;
                if (dq.size() < n) {
                    dq.push_front(x);
                    cout << "Pushed in left: " << x << "\n";
                } else {
                    cout << "The queue is full\n";
                }
            }
            if (op == "pushRight") {
                int x;
                cin >> x;
                if (dq.size() < n) {
                    dq.push_back(x);
                    cout << "Pushed in right: " << x << "\n";
                } else {
                    cout << "The queue is full\n";
                }
            }

            if (op == "popLeft") {
                if (dq.empty()) {
                    cout << "The queue is empty\n";
                } else {
                    cout << "Popped from left: " << dq.front() << "\n";
                    dq.pop_front();
                }
            }

            if (op == "popRight") {
                if (dq.empty()) {
                    cout << "The queue is empty\n";
                } else {
                    cout << "Popped from right: " << dq.back() << "\n";
                    dq.pop_back();
                }
            }
        }
    }
}

