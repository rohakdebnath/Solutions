#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    i64 findNthDigit(i64 n) {
        auto find = [&] (i64 x) -> i64 { //finds the sum of digits till the xth concat
            i64 s = 0, d = 9;
            while (x) {
                s += to_string(d).size() * min(x, d);
                x -= min(x, d);
                d *= 10;
            }
            return s;
        };
        i64 l = 0, r = 1;
        while (find(r) < n) r *= 2;
        while (r - l > 1) {
            i64 m = l + (r - l) / 2;
            if (find(m) < n) l = m;
            else r = m;
        }
        return (to_string(l + 1)[n - 1 - find(l)]) - '0';
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution s;
    i64 n; cin >> n;
    cout << s.findNthDigit(n) << '\n';
    return 0;
}
