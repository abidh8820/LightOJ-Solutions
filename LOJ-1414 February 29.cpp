#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

LL find(LL x) {
    LL ret = x / 4 + x / 400 - x / 100;
    return ret;
}

bool leap(LL x) {
    if (x % 400 == 0) return true;
    if (x % 100 == 0) return false;
    if (x % 4 == 0) return true;
    return false;
}

int main() {
    map<string, LL> val = {{"January", 1},  {"February", 2},  {"March", 3},
                           {"April", 4},    {"May", 5},       {"June", 6},
                           {"July", 7},     {"August", 8},    {"September", 9},
                           {"October", 10}, {"November", 11}, {"December", 12}};

    LL t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        LL date1, year1, date2, year2;
        string month1, month2;

        cin >> month1;
        scanf("%d, %d", &date1, &year1);

        cin >> month2;
        scanf("%d, %d", &date2, &year2);

        if (year1 == year2) {
            if (!leap(year1)) {
                cout << "0\n";
                continue;
            }
            if (val[month1] <= 2 && (val[month2] > 2 or val[month2] == 2 && date2 == 29)) cout << "1\n";
            else cout << "0\n";
            continue;
        }

        LL ans = 0;

        if (val[month1] <= 2 && leap(year1)) ans++;
        if ((val[month2] > 2 or val[month2] == 2 && date2 == 29) && leap(year2)) ans++;

        year1++, year2--;

        ans += find(year2) - find(year1 - 1);

        cout << ans << "\n";
    }
}

