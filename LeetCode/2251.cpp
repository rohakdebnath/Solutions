#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>&& a, vector<int>&& p) {
        int n = a.size(), m = p.size();
        vector<int> comp;
        auto cid = [&] (int x) {
            return lower_bound(comp.begin(), comp.end(), x) - comp.begin();
        };
        for (int i = 0; i < n; ++i) {
            comp.push_back(a[i][0]);
            comp.push_back(a[i][1] + 1);
        }
        for (int i = 0; i < m; ++i) {
            comp.push_back(p[i]);
        }
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());
        int k = comp.size();
        vector<int> d (k);
        for (int i = 0; i < n; ++i) {
            int x = cid(a[i][0]);
            int y = cid(a[i][1] + 1);
            ++d[x];
            --d[y];
        }
        partial_sum(d.begin(), d.end(), d.begin());
        vector<int> ans (m);
        for (int i = 0; i < m; ++i) {
            ans[i] = d[cid(p[i])];
        }

        return ans;
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution a;
    auto x = a.fullBloomFlowers({{1,6},{3,7},{9,12},{4,13}}, {2, 3, 7, 11});
    for (int i = 0; i < x.size(); ++i) {
        cout << x[i] << " \n"[i == x.size() - 1];
    }
    return 0;
}
