#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
class Solution {
public:
    vector<string> addOperators(string s, i64 target) {
        vector<string> ans;
        const string p = "+-*";
        i64 n = s.size();
        //t: 0 means mult pu and u and add to hard,
        //   1 means subtract 
        auto dfs = [&] (auto&& self, i64 hard, i64 pu, i64 u, i64 i, string&& build) -> void{
            if (i == n) {
                i64 f = hard + pu * u;
                if (f == target) ans.push_back(build);
                return;
            }
            if (u != 0) {
                i64 x = (u == -1 ? 0 : u * 10) + s[i] - '0';
                self(self, hard, pu, x, i + 1, build + s[i]);
            } 
            if (p.find(build[build.size() - 1]) == string::npos) {
                self(self, hard + pu * u, 1, -1, i, build + '+');
                self(self, hard + pu * u, -1, -1, i, build + '-');
                self(self, hard, pu * u, -1, i, build + '*');
            }
        };
        dfs(dfs, 0, 1, s[0] - '0', 1, string() + s[0]);
        return ans;
    }
};

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution a;
    string s; cin >> s;
    i64 t; cin >> t;
    auto p = a.addOperators(s, t);
    for (string x: p) {
        cout << x << '\n';
    }
    return 0;
}
