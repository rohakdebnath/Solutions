// decimal to base k conversion. cannot convert negative numbers in positive bases correctly, all other combos are fine including -ve and +ve nums in -ve base
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    if (n == 0) {
        cout << "0\n";
        return;
    }
    string s = "";
    while (n) {
        int x = n % k;
        n /= k;
        if (x < 0) {
            x += abs(k);
            n += 1;
        }
        s += char('0' + abs(x));
    }
    reverse(s.begin(), s.end());
    s = s.substr(s.find_first_not_of('0'));
    cout << s << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
