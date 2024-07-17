#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve() {
    int N, K; cin >> N >> K;
    int lim = (N * N - (N & 1)) / 2;
    if (K & 1 or K > lim){
        cout << "NO\n";
        return;
    }
    vector<int> sums;
    K /= 2;
    int hi = N - 1;
    while (K and hi > 0){
        if (K >= hi){
            sums.push_back(hi);
            K -= hi;
        }
        hi -= 2;
    }
    vector<int> ans (N, -1);
    int id = 0;
    for (int i: sums){
        ans[id] = i + 1 + id;
        ans[i + id] = id + 1;
        ++id;
    }
    rep(i, 0, N) {
        if (ans[i] == -1 and ans[i + 1] == -1 and i + 1 < N and K){
            ans[i] = i + 2;
            ans[i + 1] = i + 1;
            --K; ++i;
        } else if (ans[i] == -1){
            ans[i] = i + 1;
        }
    }
    cout << "YES\n";
    rep(i, 0, N) cout << ans[i] << " \n"[i == N - 1];
}

signed main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
