#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    VI alo (26);
    VI uniq (n + 1);
    rep(i, 0, n){
        uniq[i + 1] = uniq[i] + (alo[s[i] - 'a'] == 0);
        alo[s[i] - 'a'] = 1;
    }
    cout << accumulate(all(uniq), 0) << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
