#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    string largestMultipleOfThree(vector<int>& a) {
        int n = a.size();
        vector<multiset<int>> d (3);
        int s = 0;
        for (int i = 0; i < n; ++i) {
            d[a[i] % 3].insert(a[i]);
            s += a[i];
        }
        if (s % 3 == 1) {
            if (d[1].size() > 0) {
                d[1].erase(d[1].begin());
            } else {
                d[2].erase(d[2].begin());
                d[2].erase(d[2].begin());
            }
        } else if (s % 3 == 2) {
            if (d[2].size() > 0) {
                d[2].erase(d[2].begin());
            } else {
                d[1].erase(d[1].begin());
                d[1].erase(d[1].begin());
            }
        }
        string ans = "";
        s = 0;
        for (int i = 0; i < 3; ++i) {
            for (int x: d[i]) ans += char('0' + x), s += x;
        }
        sort(ans.begin(), ans.end(), greater<char>());

        return s == 0 ? "0" :ans;
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return 0;
}

