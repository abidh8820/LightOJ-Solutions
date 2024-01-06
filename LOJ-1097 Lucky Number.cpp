#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

/*
    Operations :
    find_by_order : returns an iterator to the k-th
    largest element (counting from zero).
    order_of_key :  returns the number of items in
    a set that are strictly smaller than our item.
    # to use as a multiset just insert a pair<int,int> with unique second
   element, change int to pair<int,int> in typedef part
*/

const int N = 1429439;

int ans[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    ordered_set st;
    for (int i = 1; i < N; i += 2) st.insert(i);
    ans[1] = 1;

    for (int i = 2; i <= 100000; i++) {
        int x = *st.find_by_order(i - 1);
        ans[i] = x;

        vector<int> del;
        for (int j = x; j < N; j += x) {
            auto it = st.find_by_order(j - 1);
            if (it == st.end()) break;
            del.push_back(*it);
        }

        for (int e : del) st.erase(e);
    }

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        cout << ans[n] << "\n";
    }
}

