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
    int n; cin >> n;
    int curtop; cin >> curtop;
    VI s1 (n), s2 (n); rep(i, 0, n) cin >> s1[i] >> s2[i];
    rep(i, 1, n){
        VI used (7);
        used[s1[i]] = used[s2[i]] = used[7 - s1[i]] = used[7 - s2[i]] = 1;
        VI unused;
        rep(j, 1, 7){
            if (!used[j]) unused.push_back(j);
        }
        if (7 - curtop == unused[0] or 7 - curtop == unused[1]){
            curtop = (unused[0] == 7 - curtop ? unused[1]: unused[0]);
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
