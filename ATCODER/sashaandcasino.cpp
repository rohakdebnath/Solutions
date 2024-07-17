#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int k, x, a; cin >> k >> x >> a;
    i64 sum = 0;
    vector<int> ans (x + 1);
    rep(i, 0, x + 1){
        i64 y = sum/(k - 1) + 1; //https://codeforces.com/blog/entry/125943?#comment-1117744
        ans[i] = y;
        sum += y;
        if (sum > a){
            cout << "NO\n";
            return;
        }
    }
    rep(i, 0, x + 1) cout << ans[i] << " \n"[i == x];
    cout << "YES\n";
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
