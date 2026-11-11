#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    char findKthBit(int n, int k) {
        auto rec = [&] (auto&& self, int n, int k, int inv) -> int {
            if (n == 1) return inv;
            int s = 1 << (n - 1);
            if (k == s) return 1 ^ inv;
            else if (k > s) {
                return self(self, n - 1, 2 * s - k, inv ^ 1);
            } else {
                return self(self, n - 1, k, inv);
            }
        };
        return (rec(rec, n, k, 0) + '0');
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution a;
    int n, k; cin >> n >> k;
    cout << a.findKthBit(n, k) << '\n';
    return 0;
}
