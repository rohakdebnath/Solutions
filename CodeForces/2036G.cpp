#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 ask(i64 l, i64 r) {
    cout << "xor " << l << ' ' << r << endl;
    i64 x; cin >> x;
    return x;
}
void solve() {
    i64 n; cin >> n;
    i64 a, b;
    i64 x = ask(1, n);
    
    i64 l = 1, r = n;
    if (x == 0) { //the two numbers have the same msb and the third number doesnt have it on, hence we can find the smaller number by xorring ranges of powers of 2 - 1
        i64 h = 1;
        while ((a = ask(1, h)) == 0) h = 2 * h + 1;
    } else {
        while (l != r) {
            i64 m = l + (r - l) / 2;
            if (ask(1, m) == 0) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        a = ask(1, l);
    }
    x = x ^ a;
    l = a + 1, r = n;

    while (l != r) {
        i64 m = l + (r - l) / 2;
        if (ask(a + 1, m) == 0) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    b = ask(a + 1, l);
    cout << "ans " << a << ' ' << b << ' ' << (x ^ b) << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
//lore:
//trying to isolate the smallest number, then b and c be be found very easily using simple binsrch
