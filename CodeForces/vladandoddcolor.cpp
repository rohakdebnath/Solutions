#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 N, K; cin >> N >> K;
    i64 l = 1;
    while (true){
        int t = (N + 1) / 2;
        if (K <= t){
            cout << l * (2 * K - 1) << '\n';
            return;
        }
        K -= t;
        N /= 2;
        l *= 2;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
