#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector<int> zfunc(string& s){
    int n = s.size();
    vector<int> z (n);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r){
            z[i] = min<int>(r - i, z[i - l]);
        }
        while(z[i] + i < n and s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), m = goal.size();
        goal = goal + '#' + s + s;
        auto v = zfunc(goal);
        return *max_element(v.begin() + m + 1, v.end()) >= m;
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return 0;
}
