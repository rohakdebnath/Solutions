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
    vector<pair<i64, i64>>  dot (N);
    rep(i, 0, N){
        cin >> dot[i].first >> dot[i].second;
    }
    i64 ans = N;
    i64 mfq = 0;
    map<pair<i64, i64>, i64> f;
    rep(i, 0, N){
        rep(j, 0, N){
            if (i == j) continue;
            ++f[{dot[j].first - dot[i].first, dot[j].second - dot[i].second}];
            mfq = max(mfq, f[{dot[j].first - dot[i].first, dot[j].second - dot[i].second}]);
        }
    }
    ans -= mfq;
    cout << ans << '\n';
    return 0;
}
