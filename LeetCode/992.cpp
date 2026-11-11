#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& a, int k) {
        return leqk(a, k) - leqk(a, k - 1);
    }
    int leqk(vector<int>& a,int k){
        int n = a.size();
        map<int, int> f;
        int j = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            ++f[a[i]];
            while (f.size() > k) {
                if (--f[a[j]] == 0) f.erase(a[j]);
                ++j;
            }
            ans += i - j + 1;
        }
        return ans;
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    Solution s; 
    cout << s.subarraysWithKDistinct(a, k) << '\n';
    return 0;
}
