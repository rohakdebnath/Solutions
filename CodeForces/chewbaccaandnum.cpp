#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    string s; cin >> s;
    rep(i, 0, s.size()){
        if (i == 0 and s[i] == '9') continue;
        if (s[i] - '0' > 9 - s[i] + '0') s[i] = 9 - (s[i] - '0') + '0';
    }
    cout << s << '\n';
    return 0;
}
