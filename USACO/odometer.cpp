//dp[i][j][k][t] = ith digit, j is the frequency of the digit, k is if we started pouring non zero elements at all, t is the character bound
//we start with offsetted frequency of 18, if digit is targ, +1, otherwise -1, if final frequency is >= 18 means targ is atleast as many as the other digits
//simultaneous case for duplicates (we need to delete the cases where both >= 18 since that will be counted twice once for each) if handled by the same code, if c is either of the two targs
//then we run the corresponding modified dfs (using the same dfs code), this time however freq == 18 means regardless of leading zeros, frequency of both of them are same, thus they cancel each other perfectly
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string name = "odometer";
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    string x, y; cin >> x >> y;
    x = to_string(stoll(x) - 1);
    auto check = [&] (string s, int t, int p) {
        int n = s.size();
        vector<vector<vector<vector<i64>>>> dp (n, vector<vector<vector<i64>>> (36, vector<vector<i64>> (2, vector<i64> (2, -1))));
        auto dfs = [&] (auto&& self, int i, int j, int started, int under) -> i64{
            if (i == n) {
                if (!started) return 0;
                if (p != -1) {
                    return j == 18;
                }
                return (j >= 18);
            }
            if (dp[i][j][started][under] != -1) return dp[i][j][started][under];
            i64 ans = 0;
            for (int c = 0; c <= 9; ++c) {
                if (!started and c == 0) {
                    ans += self(self, i + 1, j, 0, 0);
                } else {
                    int d = s[i] - '0';
                    int lim = under ? d : 9;
                    if (c <= lim) {
                        if (p != -1) {
                            if (c == t or c == p) ans += self(self, i + 1, j + 2 * (c == t) - 1, 1, under and (c == d));
                        } else ans += self(self, i + 1, j + 2 * (c == t) - 1, 1, under and (c == d));
                    }
                    else break;
                }
            }
            return dp[i][j][started][under] = ans;
        };
        return dfs(dfs, 0, 18, 0, 1);
    };
    auto run = [&] (string s) {
        i64 ans = 0;
        for (int i = 0; i <= 9; ++i) {
            ans += check(s, i, -1);
        }
        i64 dup = 0;
        for (int i = 0; i <= 9; ++i) {
            for (int j = 0; j <= 9; ++j) {
                dup += check(s, i, j);
            }
        }
        return ans - dup / 2;
    };
    cout << run(y) - run(x) << '\n';
    return 0;
}
