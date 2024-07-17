#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

int main()
{
    UNSYNC
    i64 N; cin >> N;
    vector<pair<i64, i64>> A(N);
    rep(i, 0, N){
        i64 x, t; cin >> x >> t;
        A[i] = {x - t, x + t};
    }

    sort(all(A), [&] (auto& i, auto& j) {return i.first == j.first ? i.second > j.second : i.first < j.first;});
    vector<i64> dp (N + 1, INT64_MAX); dp[0] = - INT64_MAX;
    vector<vector<pair<i64, i64>>> ans (N + 1);
    rep(i, 0, N){
        i64 l = lower_bound(all(dp), A[i].second) - dp.begin();
        dp[l] = A[i].second;
        ans[l].push_back(A[i]);
    }
    i64 S = 0;
    rep(i, 0, N + 1) if (dp[i] < INT64_MAX) S = i;
    cout << S << '\n';
    rep(i, 1, S + 1){
        for (auto c: ans[i]){
            i64 s = (c.first + c.second) / 2;
            i64 t = (c.second - c.first) / 2;
            cout << s << ' ' << t << ' ' << i << '\n';
        }
    }
    return 0;
}
