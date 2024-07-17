#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve() {
    int N; cin >> N;
    string a, b; cin >> a >> b;
    vector<int> P (N + 1);
    rep(i, 0, N) P[i + 1] = P[i] + (i - 2 >= 0 and i + 2 < N and (a[i] == '1' or ((a[i - 2] == '0' or b[i - 1] == '1') and (a[i + 2] == '0' or b[i + 1] == '1'))));

    int Q; cin >> Q;
    while(Q--){
        int l, r; cin >> l >> r; --l;
        int ans = 0;
        if (r - l >= 5) ans += P[r - 2] - P[l + 2];
        rep(i, l, r){
            if (i >= l + 2 and i + 2 < r) i = r - 2;
            ans += (a[i] == '1') or (((b[i - 1] == '1' and i - 1 >= l) or (a[i - 2] == '0' and i - 2 >= l)) and ((b[i + 1] == '1' and i + 1 < r) or (a[i + 2] == '0' and i + 2 < r)));
        }
        cout << ans << '\n';
    }
}

signed main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
