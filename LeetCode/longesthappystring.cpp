#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        array<array<int, 2>, 3> v;
        string s = "";
        v[0] = {a, 0}, v[1] = {b, 1}, v[2] = {c, 2};
        sort(v.begin(), v.end());

        v[2][0] = min(v[2][0], 2 * (v[0][0] + v[1][0] + 1));
        while (2 * (v[0][0] + v[1][0] + 1) > v[2][0] and v[2][0]) {
            if (v[2][0]) s += char(v[2][1] + 'a'), --v[2][0];
            if (v[1][0]) s += char(v[1][1] + 'a'), --v[1][0];
            sort(v.begin(), v.end());
        }   
        while(v[2][0]) {
            for (int i = 0; i < 2 and v[2][0] > 0; ++i) s += char(v[2][1] + 'a'), --v[2][0];
            if (v[1][0]) s += char(v[1][1] + 'a'), --v[1][0];
            else if (v[0][0]) s += char(v[0][1] + 'a'), --v[0][0];
        }

        return s;
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution a; 
    int x, b, c; cin >> x >> b >> c;
    cout << a.longestDiverseString(x, b, c) << '\n';
    return 0;
}
