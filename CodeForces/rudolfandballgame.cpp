#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int n, m, x; cin >> n >> m >> x;
    bitset<1000> bs;
    bs[x - 1] = 1;
    rep(i, 0, m){
        int a; cin >> a;
        char c; cin >> c;
        if (c == '?'){
            bs = ((bs >> a) | (bs << (n - a))) | ((bs << a) | (bs >> (n - a)));
        } else if (c == '1'){
            bs = (bs >> a) | (bs << (n - a));
        } else {
            bs = (bs << a) | (bs >> (n - a));
        }
    }
    vector<int> ans;
    rep(i, 0, n){
        if (bs[i]) ans.push_back(i + 1);
    }
    int t = ans.size();
    cout << t << '\n';
    rep(i, 0, t) cout << ans[i] << " \n"[i == t - 1];
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
