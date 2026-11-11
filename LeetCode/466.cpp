#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    int getMaxRepetitions(string s, int ns, string t, int nt) { //find occurances of t on s as substring
        int n = s.size(), m = t.size();
        vector<int> shift (n); //shift[i] = shift needed in s to complete one occurance of t starting from ith character in s
        for (int p = 0; p < n; ++p) {
            int j = p;
            for (int i = 0; i < m; ++i) {
                if (s.find(t[i]) == string::npos) return 0;
                while (s[j % n] != t[i]) ++j;
                ++j;
            }
            shift[p] = j - p;
        }

        int j = 0, seg = 0;
        while (true) {
            for (int i = 0; i < nt; ++i) {
                j += shift[j % n];
            }
            if (j > n * ns) break;
            else ++seg;
        }
        return seg;
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution a;
    cout << a.getMaxRepetitions("phqghumeaylnlfdxfircvscxggbwkfnqduxwfnfozvsrtkjpre", 1000000, "pggxr", 100) << '\n';
    return 0;
}

//abab
//cc
//dcbadcbadcba
//abcd
