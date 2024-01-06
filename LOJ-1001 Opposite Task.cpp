#include <bits/stdc++.h>
using namespace std;

vector<int> problemsStored(int n) {
    vector<int> res ;
    int x = min(10,n);
    res.push_back(x);
    res.push_back(n-x);
    return res;
}

int main() {
    int cases;
    scanf("%d", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno) {
        int n;
        scanf("%d", &n);
        
        vector<int> ans = problemsStored(n);
        printf("%d %d\n", ans[0], ans[1]);
    }
    return 0;
}
