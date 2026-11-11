#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    int maxJumps(vector<int>& a, int d) {
        int n = a.size();
        vector<int> dp (n, -1); //dp[i] = max points you can get by starting at i
        function<int(int)> rec = [&] (int i) -> int {
            if (dp[i] != -1) return dp[i];
            int x = 0;
            int l = true, r = true;
            for (int j = 1; j <= d; ++j) {
                if (i - j >= 0 and a[i - j] < a[i] and l) x = max(x, rec(i - j));
                else l = false;

                if (i + j < n and a[i + j] < a[i] and r) x = max(x, rec(i + j));
                else r = false;
            }
            return dp[i] = x + 1;
        };
        for (int i = 0; i < n; ++i) {
            if (dp[i] == -1) rec(i);
        }
        for (int i = 0; i < n; ++i) {
            cout << dp[i] << " \n"[i == n - 1];
        }
        return *max_element(dp.begin(), dp.end());
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    int d; cin >> d;
    Solution s; 
    cout << s.maxJumps(a, d) << '\n';
    return 0;
}
