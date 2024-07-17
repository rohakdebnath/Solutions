#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve() {
    int N; cin >> N;
    string s; cin >> s;
    vector<i64> dp (N + 4); //cool simplication read editorial. need to know everything about larger index states before calcing smaller index ones, hence back to front iteration is necessary
    per(i, N, 1){
        if (s[i - 1] == '1'){
            dp[i] = N - i + 1 + dp[i + 3];
        } else {
            dp[i] = dp[i + 1];
        }
    }
    cout << accumulate(all(dp), 0LL) << '\n';
}

signed main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
